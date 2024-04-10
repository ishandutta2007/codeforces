#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        int a[55];
        int b[55];
        scanf("%d",&n);
        int Mina=1e9+7,Minb=1e9+7;
        for(int i =0;i<n;i++){
            scanf("%d",&a[i]);
            Mina=min(Mina,a[i]);
        }
        for(int i = 0;i<n;i++)scanf("%d",&b[i]),Minb=min(Minb,b[i]);
        LL ans=0;
        for(int i = 0;i<n;i++)ans+=max(a[i]-Mina,b[i]-Minb);
        printf("%lld\n",ans);
    }
}