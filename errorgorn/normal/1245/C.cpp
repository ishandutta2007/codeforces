#include <iostream>
#include <string>
using namespace std;
string s;
int memo[100005];
const long long MOD=1000000007;
int fibo(int i){
    if (i==1 || i==0) return 1;
    else if (memo[i]) return memo[i];
    else return memo[i]=(fibo(i-1)+fibo(i-2))%MOD;
}
int main(){
    cin>>s;
    for (int x=0;x<s.size();x++){
        if (s[x]=='m' || s[x]=='w'){
            printf("0");
            return 0;
        }
    }

    long long ans=1;
    int c=0;
    if (s[0]=='u' || s[0]=='n') c=1;
    for (int x=1;x<s.size();x++){
        if (c && s[x]==s[x-1]) c++;
        else if (s[x]!=s[x-1]){
            ans=(ans*fibo(c))%MOD;
            if (s[x]=='u' || s[x]=='n') c=1;
            else c=0;
        }
    }
    ans=(ans*fibo(c))%MOD;
    printf("%lld\n",ans);
}