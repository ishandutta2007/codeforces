#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n;
long long a,b;
string s;
long long memo[200005][2];
long long dp(int i,int lifted){
    if (i==-1) {
        return lifted?1e15:b;
    }
    if (memo[i][lifted]!=-1) return memo[i][lifted];
    if (lifted==1) return memo[i][lifted]=min(dp(i-1,0)+a,dp(i-1,1))+2*b+a;
    else{
        if (s[i]=='1' || s[i+1]=='1') return memo[i][lifted]=1e15;
        else return memo[i][lifted]=min(dp(i-1,1)+a,dp(i-1,0))+b+a;
    }
}
int main(){
    int TC;
    cin>>TC;
    while (TC--){
        memset(memo,-1,sizeof(memo));
        cin>>n>>a>>b;
        cin>>s;
        s+='0';

        cout<<dp(n-1,0)<<endl;
    }
}