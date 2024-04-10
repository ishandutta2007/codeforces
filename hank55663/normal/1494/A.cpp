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
void solve(){
    char c[55];
    scanf("%s",c);
    int a[55];
    int n=strlen(c);
    for(int i = 0;c[i]!=0;i++){
        a[i]=c[i]-'A';
    }
    for(int i = 0;i<8;i++){
        int cnt=0;
        int ok=1;
        for(int j = 0;j<n;j++){
            if(i&(1<<a[j]))cnt++;
            else cnt--;
            if(cnt<0)ok=0;
        }
        if(cnt)ok=0;
        if(ok){
            printf("YES\n");
            return ;
        }
    }
    printf("NO\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/