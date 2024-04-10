#include<bits/stdc++.h>
using namespace std;
string s[2];
void func(int l,int r,int id)
{
    if((r-l)&1)return;
    int m=l+r>>1;
    func(l,m,id);func(m,r,id);
    bool swapf=0;
    for(int i=0;i<m-l;i++)
    {
        if(s[id][l+i]!=s[id][m+i])
        {
            swapf=s[id][l+i]>s[id][m+i];
            break;
        }
    }
    if(swapf)for(int i=0;i<m-l;i++)swap(s[id][l+i],s[id][m+i]);
}
int main()
{
    cin>>s[0]>>s[1];
    func(0,s[0].size(),0);
    func(0,s[1].size(),1);
    puts(s[0]==s[1]?"YES":"NO");
    return 0;
}