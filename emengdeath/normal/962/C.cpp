#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int d[100];
int get(int x){
    int y=0;
    while (x)x-=(x&-x),y++;
    return y;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>s;
    ans=s.size();
    for (int i=(1<<s.size())-1;i;i--){
        int num=s.size()-get(i);
        if (num>=ans)continue;
        int x=0;
        d[0]=0;
        for (int j=0;j<s.size();j++)
            if (i&(1<<j))
                d[++d[0]]=s[j]-'0';
        if (!d[1])continue;
        for (int j=1;j<=d[0];j++)
            x=x*10+d[j];
        int y=sqrt(x);
        if ((long long)y*y==x||(long long)(y+1)*(y+1)==x)ans=num;
    }
    if (ans==s.size())cout<<-1;
    else
        cout<<ans;
    return 0;
}