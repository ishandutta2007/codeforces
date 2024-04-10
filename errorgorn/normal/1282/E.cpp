#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
struct custom_hash {
    typedef long long ll;
    typedef unsigned long long ull;
    const ull FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    static ull splitmix64(ull x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(ll x) const {
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(const pair<int,int> &i)const{
        return splitmix64((((ll)i.first)^(((ll)i.second)<<32))+FIXED_RANDOM);
    }
};

struct linked{
    int val;
    linked *l,*r;
    linked(int i){
        val=i;
        l=this;
        r=this;
    }
    void left_add(int i){
        linked *node=new linked(i);
        node->l=this->l;
        this->l=node;
        node->l->r=node;
        node->r=this;
    }
    void right_add(int i){
        linked *node=new linked(i);
        node->r=this->r;
        this->r=node;
        node->r->l=node;
        node->l=this;
    }
};

int n;
unordered_map<ii,vector<ii>,custom_hash> m;
vector<int> fin;
bool taken[100005];
inline ii format(int a,int b){
    if (a>b) return ii(b,a);
    else return ii(a,b);
}
int main(){
    //freopen("input.txt","r",stdin);
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d",&n);
        m.clear();

        int a,b,c;
        for (int x=1;x<=n-2;x++){
            scanf("%d%d%d",&a,&b,&c);
            if (!m.count(format(a,b))) m[format(a,b)]=vector<ii>();
            if (!m.count(format(b,c))) m[format(b,c)]=vector<ii>();
            if (!m.count(format(a,c))) m[format(a,c)]=vector<ii>();
            m[format(a,b)].push_back(ii(c,x));
            m[format(b,c)].push_back(ii(a,x));
            m[format(a,c)].push_back(ii(b,x));
            taken[x]=false;
        }
        fin.push_back(n-2);
        taken[n-2]=true;
        linked *list=new linked(a);
        list->right_add(b);
        list->right_add(c);

        ii temp;
        for (int x=3;x<n;x++){
            retry:
            if (m.count(format(list->val,list->r->val))){
                //printf("%d %d\n",list->val,list->r->val);
                for (auto &it:m[format(list->val,list->r->val)]){
                    if (taken[it.second]) continue;
                    list->right_add(it.first);
                    list=list->r;
                    taken[it.second]=true;
                    fin.push_back(it.second);
                    goto end;
                }
            }
            if (m.count(format(list->val,list->l->val))){
                //printf("%d %d\n",list->val,list->r->val);
                for (auto &it:m[format(list->val,list->l->val)]){
                    if (taken[it.second]) continue;
                    list->left_add(it.first);
                    list=list->l;
                    taken[it.second]=true;
                    fin.push_back(it.second);
                    goto end;
                }
            }
            list=list->l;
            goto retry;
            end:;
        }

        for (int x=0;x<n;x++){
            printf("%d ",list->val);
            list=list->r;
        }
        printf("\n");
        for (int x=0;x<n-2;x++){
            printf("%d ",fin.back());
            fin.pop_back();
        }
        printf("\n");
    }
}