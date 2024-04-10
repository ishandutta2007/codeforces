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

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

struct node {
    node* next[26];
    bool valid;
};

node all[1100000];
int nodecnt;

node* alloc_node() {
    return &all[nodecnt++];
}

char str[110000];

void add_word(char* str, node* cur) {
    if (*str == '\0') return;
    else if (cur->next[*str - 'a'] != NULL) add_word(str+1, cur->next[*str - 'a']);
    else add_word(str+1, cur->next[*str - 'a'] = alloc_node());
}

bool dfs_norm(node* cur) {
    for (int i = 0; i < 26; i++) {
        if (cur->next[i] != NULL && !dfs_norm(cur->next[i])) return true;
    }
    return false;
}

bool dfs_miser(node* cur) {
    bool has = false;
    for (int i = 0; i < 26; i++) {
        if (cur->next[i] != NULL && !dfs_miser(cur->next[i])) return true;
        if (cur->next[i] != NULL) has = true;
    }
    return !has;
}

int n, k;

int main() {
    scanf("%d %d", &n, &k);

    node* root = alloc_node();

    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        add_word(str, root);
    }

    bool win_norm = dfs_norm(root);
    bool win_miser = dfs_miser(root);

    if (win_miser && win_norm) {
        printf("First\n");
    }
    else if (win_norm) {
        printf("%s\n", k % 2 == 1 ? "First" : "Second");
    }
    else {
        printf("Second\n");
    }
}