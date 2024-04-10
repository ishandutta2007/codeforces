#include<iostream>
#include<cstdio>
#include<bitset>
#include<string>
using namespace std;
bitset<100001> pos[26],ans;
int n;
string s;
int main()
{
    cin>>s>>n;
    int len=s.length();
    for(int i=0;i<len;++i)
        pos[s[i]-'a'][i]=1;
    while(n--)
    {
        int opt;
        cin>>opt;
        if(opt==1)
        {
            int p;
            char c;
            cin>>p>>c;
            --p;
            pos[s[p]-'a'][p]=0;
            s[p]=c;
            pos[c-'a'][p]=1;
        }
        if(opt==2)
        {
            int l,r;
            string str;
            cin>>l>>r>>str;
            int m=str.length();
            --l;
            if(r-l<m)
            {
                cout<<"0\n";
                continue;
            }
            ans.reset();
            ans=~ans;
            ans=(ans<<l)^(ans<<(r-m+1));
            for(int i=0;i<m;++i)
            {
                if(i)
                    ans<<=1;
                ans&=pos[str[i]-'a'];
            }
            cout<<ans.count()<<'\n';
        }
    }
    return 0;
}