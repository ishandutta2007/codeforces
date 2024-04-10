#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int n,m,x[100010],p;
string w[100010],tt,xx,yy;
vector<string> s,t,s2,t2,u,v;
char ss[10];
map<string,int> f;
inline void pr(string yy,string xx)
{
    printf("move %s %s\n",yy.c_str(),xx.c_str());
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   for(j=i;j;j/=10)
	     w[i].push_back(j%10+'0');
	   reverse(w[i].begin(),w[i].end());
	   f[w[i]]=i;
	  }
	for(i=1;i<=n;i++)
	  {
	   scanf("%s%d",&ss,&j);
	   tt=ss;
	   if(j==1)
	     {
		  s.push_back(tt);
		  m++;
		 }
	   else
	     t.push_back(tt);
	  }
	for(i=0;i<s.size();i++)
	  if(f[s[i]])
	    {
	     if(f[s[i]]<=m)
		   x[f[s[i]]]=1;
		 else
		   {
		    x[f[s[i]]]=1;
		    s2.push_back(s[i]);
		   }
		 s[i]=s[s.size()-1];
		 s.resize(s.size()-1);
		 i--;
		}
	for(i=0;i<t.size();i++)
	  if(f[t[i]])
	    {
	     if(f[t[i]]>m)
		   x[f[t[i]]]=1;
		 else
		   {
		    x[f[t[i]]]=1;
		    t2.push_back(t[i]);
		   }
		 t[i]=t[t.size()-1];
		 t.resize(t.size()-1);
		 i--;
		}
		//for(i=0;i<s2.size();i++)
		//cout<<s2[i]<<"\n";
	for(i=1;i<=m;i++)
	  if(!x[i])
	    u.push_back(w[i]);
	for(;i<=n;i++)
	  if(!x[i])
	    v.push_back(w[i]);
	k=s.size()+t.size()+s2.size()+t2.size();
	printf("%d\n",k+(k && u.size()==0 && v.size()==0));
	if(k && u.size()==0 && v.size()==0)
	  {
	   xx="a";
	   yy=s2[s2.size()-1];
	   pr(yy,xx);
	   k=f[yy];
	   v.push_back(w[k]);
	   s2.resize(s2.size()-1);
	   s.push_back(xx);
	  }
	while(s.size()+t.size()+s2.size()+t2.size()>0)
	  {
			//cout<<u.size()<<" "<<v.size()<<" "<<t.size()<<"\n";
	   if(v.size()>0)
	     if(t2.size()>0)
	       {
			xx=v[v.size()-1];
			yy=t2[t2.size()-1];
			pr(yy,xx);
			k=f[yy];
			u.push_back(w[k]);
	        v.resize(v.size()-1);
	        t2.resize(t2.size()-1);
		   }
		 else
	       {
			xx=v[v.size()-1];
			yy=t[t.size()-1];
			pr(yy,xx);
	        v.resize(v.size()-1);
	        t.resize(t.size()-1);
		   }
	   else
	     if(s2.size()>0)
	       {
			xx=u[u.size()-1];
			yy=s2[s2.size()-1];
			pr(yy,xx);
			k=f[yy];
			v.push_back(w[k]);
	        u.resize(u.size()-1);
	        s2.resize(s2.size()-1);
		   }
		 else
	       {
			xx=u[u.size()-1];
			yy=s[s.size()-1];
			pr(yy,xx);
	        u.resize(u.size()-1);
	        s.resize(s.size()-1);
		   }
	  }
	return 0;
}