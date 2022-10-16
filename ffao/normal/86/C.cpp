#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


struct ACnode{
    ACnode *f, *p, *l; //funcao de fail, primeiro filho, irmao
    int o; //marca se ha uma string acabando
    char c; //letra
    void reset(){
        p = l = f = NULL;
        o = -1;
    }
    ACnode* son(char c){ //retorna filho 'c'
        ACnode* it;
        for (it = p; it != NULL; it = it->l){
            if (it->c == c){
                return it;
            }
        }
        return NULL;
    }
    void add(char c, ACnode* it){ //adiciona filho
        it->c = c;
        it->l = p;
        p = it;
    }
};

class AhoCorasick
{
public:
    static ACnode data[];
    static int d_cnt;
    static ACnode* new_node();
    ACnode* root;
    int string_cnt;
    
    AhoCorasick();
    void add_string(char* s);
    void compute_fail();
    void reset();
};


using namespace std;


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

AhoCorasick ac;
int n, k;
int len[12];
char str[12];

char conv[128];
int dp[1100][110][11];

const int mod = 1000000009;

void solve()
{
    conv['A'] = 'A';
    conv['G'] = 'B';
    conv['C'] = 'C';
    conv['T'] = 'D';

    ac.reset();

    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%s", str);
        for (int j = 0; str[j] != '\0'; j++) str[j] = conv[str[j]];
        ac.add_string(str);
        len[i] = strlen(str);
    }
    ac.compute_fail();

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    REP(size, n) {
        REP(idx, ac.d_cnt) {
            REP(uncovered, 11) {
                REP(next_char, 4) {
                    char trans = 'A' + next_char;
                    ACnode *nxt, *p;
                    for (p = &AhoCorasick::data[idx]; p->son(trans) == NULL && p != ac.root; p = p->f);
                    
                    nxt = p->son(trans);
                    if (!nxt) nxt = ac.root;
                    //fprintf(stderr, "%d %d %c %c %d", size, idx, trans, nxt->c, nxt->o);

                    int covers = 0;
                    if (nxt->o != -1) covers = len[nxt->o];

                    int next_covered = uncovered + 1;
                    if (covers >= uncovered + 1) next_covered = 0;
                    
                    if (next_covered <= 10) {
                        //if (dp[size][idx][uncovered]) fprintf(stderr, "[%d][%d][%d] -> [%d][%d][%d] %d %d\n", size + 1, nxt - AhoCorasick::data, next_covered, size, idx, uncovered, covers, nxt->o);
                        dp[size + 1][nxt - AhoCorasick::data][next_covered] = (dp[size][idx][uncovered] + dp[size + 1][nxt - AhoCorasick::data][next_covered]) % mod;
                    }
                }
            }
        }
    }

    int ans = 0;
    REP(idx, ac.d_cnt) ans = (ans + dp[n][idx][0]) % mod;
    printf("%d\n", ans);
}
int main() {
    solve();
}


ACnode AhoCorasick::data[2100000];
int AhoCorasick::d_cnt;

ACnode* AhoCorasick::new_node(){
    data[d_cnt].reset();
    return &data[d_cnt++];
}

AhoCorasick::AhoCorasick() {
    reset();
}

void AhoCorasick::reset() {
    d_cnt = 0;
    string_cnt = 0;
    root = new_node();
}

void AhoCorasick::add_string(char* s) {
    ACnode *p = root;
    char c;
    for (int j = 0; (c = s[j]) != '\0'; j++){
        ACnode *it = p->son(c);
        if (it == NULL){
            p->add(c, it = new_node());
        }
        p = it;
    }
    p->o = string_cnt++;
}

void AhoCorasick::compute_fail() {
    std::queue<ACnode*> q;
    for (ACnode *it = root->p; it != NULL; it = it->l){
        q.push(it);
        it->f = root;
    }
    while (!q.empty()){ //calcula os fail
        ACnode *p = q.front();
        q.pop();
        for (ACnode *it = p->p; it != NULL; it = it->l){
            q.push(it);
            ACnode *jt, *kt;
            for (jt = p->f; (kt = jt->son(it -> c)) == NULL; jt = jt->f){
                if (jt == root){
                    kt = root;
                    break;
                }
            }
            it->f = kt;
            if (it->o == -1){
                it->o = kt->o;
            }
        }
    }
}