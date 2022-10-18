#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,k;
string s,p;
vector<pair<int,int> > ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>s;
        s=" "+s;
        p.clear();
        p+=" ";
        for(register int i=1;i<k;++i)
            p+="()";
        for(register int i=1;i<=(n-((k-1)<<1))>>1;++i)
            p+="(";
        for(register int i=1;i<=(n-((k-1)<<1))>>1;++i)
            p+=")";
        ans.clear();
        for(register int i=1;i<=n;++i)
            if(s[i]^p[i])
            {
                for(register int j=i+1;j<=n;++j)
                    if(s[j]==p[i])
                    {
                        ans.push_back(make_pair(i,j));
                        reverse(s.begin()+i,s.begin()+j+1);
                        break;
                    }
            }
        cout<<ans.size()<<endl;
        for(auto i:ans)
            cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}