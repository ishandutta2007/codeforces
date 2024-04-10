#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
int main(){
    int n,k,m,t;
    scanf("%d %d %d %d",&n,&k,&m,&t);
    vector<int> v;
    for(int i =1;i<=n;i++){
        if(i==k)
        v.pb(1);
        else
        v.pb(0);
    }
    while(t--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            if(x==v.size()+1)
            v.pb(x);
            else{
                x--;
                vector<int> tmp;
                for(int i=0;i<v.size();i++){
                    if(i==x)
                    tmp.pb(0);
                    tmp.pb(v[i]);
                }
                swap(tmp,v);
            }
        }
        else{
            int x;
            scanf("%d",&x);
            vector<int> v1,v2;
            x--;
            for(int i = 0;i<v.size();i++){
                if(i<=x)
                v1.pb(v[i]);
                else
                v2.pb(v[i]);
            }
            for(auto it:v1){
                if(it==1){
                    swap(v1,v);
                    break;
                }
            }
            for(auto it:v2){
                if(it==1){
                    swap(v2,v);
                    break;
                }
            }
        }
        printf("%d",v.size());
        for(int i = 0;i<v.size();i++){
            if(v[i]){
                printf(" %d\n",i+1);
                break;
            }
        }
    }
}