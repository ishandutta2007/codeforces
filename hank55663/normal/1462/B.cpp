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
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    char c[205];
    scanf("%s",c);
    if(c[0]=='2'&&c[1]=='0'&&c[2]=='2'&&c[3]=='0'){
        printf("YES\n");
    }
    else  if(c[0]=='2'&&c[1]=='0'&&c[2]=='2'&&c[n-1]=='0'){
        printf("YES\n");
    }
    else if(c[0]=='2'&&c[1]=='0'&&c[n-2]=='2'&&c[n-1]=='0'){
        printf("YES\n");
    }
    else if(c[0]=='2'&&c[n-3]=='0'&&c[n-2]=='2'&&c[n-1]=='0'){
        printf("YES\n");
    }
    else  if(c[n-4]=='2'&&c[n-3]=='0'&&c[n-2]=='2'&&c[n-1]=='0'){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}