#include<bits/stdc++.h>
#define N 100005
using namespace std;
main(){
	int n;
	scanf("%d",&n);
	string s[N];
	for(int i=0;i<n;i++)
	cin>>s[i];
	sort(s,s+n);
	map<set<string>,int> m;
	m.clear();
	map<set<string>,set<string> > ma;
	ma.clear();
	map<string,set<string> >ss;
	string host[N];
	ss.clear();
	for(int i=0;i<n;i++){
		int j;
		char cc[100];
		memset(cc,0,sizeof(cc)); 
		for(j=0;s[i][j]!=0;j++){
			if(j>7&&s[i][j]=='/')
			break;
			cc[j]=s[i][j];
		}
		host[i]=cc;
		char c[100];
		memset(c,0,sizeof(c));
		for(int k=0;s[i][j]!=0;j++,k++){
			c[k]=s[i][j];
		}
		ss[host[i]].insert(c);
	}
	for(map<string,set<string> >::iterator it=ss.begin();it!=ss.end();it++)
	{
		m[it->second]++;
		ma[it->second].insert(it->first);
	}
	int aa=0;
	for(map<set<string>,int>::iterator it=m.begin();it!=m.end();it++){
		if(it->second>1){
			aa++;
		}
	}
	printf("%d\n",aa);
	for(map<set<string>,int>::iterator it=m.begin();it!=m.end();it++){
		if(it->second>1)
		{
			set<string>::iterator it2=ma[it->first].begin();
			cout<<*it2;
			for(it2++;it2!=ma[it->first].end();it2++){
				cout<<" "<<*it2;
			}
			printf("\n");
		}
	}
}