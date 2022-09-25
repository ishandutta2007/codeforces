#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n;
string s,t;
const int MOD=1000000007;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d",&n);
        cin>>s;
        
        long long ans=s.size();
        for (int x=1;x<=n;x++){
            if (s[x-1]=='1') continue;
            
            
            if (s.size()<n){
                t=s.substr(x,s.size()-x);
                for (int i=0;i<s[x-1]-'1';i++) s+=t;
            }
                
                
            ans*=s[x-1]-'0';
            ans-=(s[x-1]-'1')*x;
            ans+=MOD;
            ans%=MOD;
        }
        
        printf("%lld\n",ans);
    }
}