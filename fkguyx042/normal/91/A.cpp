#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int i,j,m,n,p,k,f[10005][26];
char c[10005],s[1000005];
vector<int>v[26];
int main()
{
   scanf("%s",c);
   scanf("%s",s);
   int len=strlen(c);
   for (i=0;i<len;++i) v[c[i]-'a'].push_back(i);
   int Len=strlen(s);
   for (i=0;i<Len;++i) if (!v[s[i]-'a'].size()) { printf("-1\n"); return 0; } 
   for (i=0;i<len;++i)
     for (j=0;j<26;++j)
       if (v[j].size())
        {
        	  if (upper_bound(v[j].begin(),v[j].end(),i)==v[j].end())
        	    f[i][j]=v[j][0];
        	    else  f[i][j]=v[j][upper_bound(v[j].begin(),v[j].end(),i)-v[j].begin()];
        }
    int now=v[s[0]-'a'][0],ans=1;
    for (i=1;i<Len;++i)
    {
       if (f[now][s[i]-'a']<=now) ++ans;
       now=f[now][s[i]-'a'];
    }
    printf("%d\n",ans);
}