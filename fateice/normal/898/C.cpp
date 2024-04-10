#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> a;
string x[30];
vector<string> f[30],g;
inline bool cmp(string a,string b)
{
	return a.size()>b.size();
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,l,u;
	string k;
	scanf("%d",&n);
	while(n--)
	  {
	   cin>>k>>j;
	   if(!a[k])
	     {
	      a[k]=++m;
	      x[m]=k;
		 }
	   i=a[k];
	   while(j--)
	     {
		  cin>>k;
		  f[i].push_back(k);
		 }
	  }
	a.clear();
	printf("%d\n",m);
	for(i=1;i<=m;i++)
	  {
	   sort(f[i].begin(),f[i].end(),cmp);
	   for(j=0;j<f[i].size();j++)
	     if(!a[f[i][j]])
	       {
			for(l=0;l<f[i][j].size();l++)
			  {
			   k.clear();
			   for(u=l;u<f[i][j].size();u++)
			     k+=f[i][j][u];
			   a[k]=1;
			  }
			g.push_back(f[i][j]);
		   }
	   a.clear();
	   cout<<x[i]<<" "<<g.size();
	   for(j=0;j<g.size();j++)
	     cout<<" "<<g[j];
	   cout<<"\n";
	   g.clear();
	  }
	return 0;
}