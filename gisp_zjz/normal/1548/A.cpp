#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=4e5+10;
const int M=998244353;
int c[maxn],n,q,ans;
void add(int x){
    if (!c[x]) ++ans; c[x]++;
}
void del(int x){
    c[x]--; if (!c[x]) --ans;
}
int main(){
    scanf("%d%d",&n,&q);
    while (q--){
        int u,v; scanf("%d%d",&u,&v);
        if (u>v) swap(u,v);
        add(u);
    }
    scanf("%d",&q);
    while (q--){
        int op; scanf("%d",&op);
        if (op==1){
            int u,v; scanf("%d%d",&u,&v);
            if (u>v) swap(u,v);
            add(u);
        } else if (op==2){
            int u,v; scanf("%d%d",&u,&v);
            if (u>v) swap(u,v);
            del(u);
        } else {
            printf("%d\n",n-ans);
        }
    }
}