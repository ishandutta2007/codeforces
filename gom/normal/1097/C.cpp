#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=5e5+5;
int n,ans;
string s;
int in[2*N],out[2*N],both[2*N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s; int v=0,q=0,c=0,c2=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='(') c++;
            else c--;
            v=min(v,c);
        }
        for(int j=s.size()-1;j>=0;j--){
            if(s[j]==')') c2++;
            else c2--;
            q=min(q,c2);
        }
        bool inp=1,outp=1;
        if(s[0]=='('){ //try front
            if(c<0||v<0) inp=0;
        }
        else inp=0;
        if(s[s.size()-1]==')'){
            if(c>0||c>v||q<0) outp=0;
        }
        else outp=0;
        if(inp&&!outp) in[c+500000]++;
        if(!inp&&outp) out[-c+500000]++;
        if(inp&&outp) both[c+500000]++;
    }
    for(int i=0;i<=1000000;i++){
        if(in[i]<=out[i]){ ans+=in[i]; out[i]-=in[i]; in[i]=0; }
        else{ ans+=out[i]; in[i]-=out[i]; out[i]=0; }
        if(in[i]>=both[i]){ ans+=both[i]; in[i]-=both[i]; both[i]=0; }
        else{ ans+=in[i]; both[i]-=in[i]; in[i]=0; }
        if(out[i]>=both[i]){ ans+=both[i]; out[i]-=both[i]; both[i]=0; }
        else{ ans+=out[i]; both[i]-=out[i]; out[i]=0; }
        ans+=both[i]/2;
    }
    cout<<ans;
    return 0;
}