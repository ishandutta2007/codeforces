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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int b[200005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++)scanf("%d",&b[i]);
    int idx=n-1;
    map<int,int> m;
    for(int i = n-1;i>=0;i--){
        while(idx>0&&b[idx]==b[idx-1]){
            m[b[idx]]++;
            idx--;
        }
        if(idx>=0&&a[i]==b[idx]){
            idx--;
        }
        else{
            if(m[a[i]])m[a[i]]--;
            else{
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
*/