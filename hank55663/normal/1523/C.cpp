#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    v.pb(0);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x==v.back()+1)v.back()++;
        else{
            if(x==1)v.pb(x);
            else{
                while(v.back()+1!=x)v.pop_back();
                v.back()++;
            }
        }
        printf("%d",v[0]);
        for(int i = 1;i<v.size();i++)printf(".%d",v[i]);
        printf("\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/