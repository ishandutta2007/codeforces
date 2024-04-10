#include<bits/stdc++.h>
using namespace std;
int read(){int x;scanf("%d",&x);return x;}
long long zbx[100010];
long long zby[100010];
vector<int> v01;
int main(){
	int n=read();
	if(n<=4){
		printf("YES");
		return 0;
	}
	for(int i=0;i<n;i++)scanf("%lld%lld",zbx+i,zby+i);
	for(int i=2;i<n;i++)
		if((zbx[i]-zbx[0])*(zby[i]-zby[1])!=(zbx[i]-zbx[1])*(zby[i]-zby[0]))
			v01.push_back(i);
	if(v01.size()<=2){
		printf("YES");
		return 0;
	}
	int ok=1;
	for(int i=2;i<v01.size();i++)
		if((zbx[v01[i]]-zbx[v01[0]])*(zby[v01[i]]-zby[v01[1]])!=
			(zbx[v01[i]]-zbx[v01[1]])*(zby[v01[i]]-zby[v01[0]]))
			ok=0;
	if(ok){
		printf("YES");
		return 0;
	}
	int v3=v01[0];
	v01.clear();ok=1;
	for(int i=0;i<n;i++)
		if((zbx[i]-zbx[0])*(zby[i]-zby[v3])!=(zbx[i]-zbx[v3])*(zby[i]-zby[0]))
			v01.push_back(i);
	if(v01.size()<=2){
		printf("YES");
		return 0;
	}
	for(int i=2;i<v01.size();i++)
		if((zbx[v01[i]]-zbx[v01[0]])*(zby[v01[i]]-zby[v01[1]])!=
			(zbx[v01[i]]-zbx[v01[1]])*(zby[v01[i]]-zby[v01[0]]))
			ok=0;
	if(ok){
		printf("YES");
		return 0;
	}
	v01.clear();ok=1;
	for(int i=0;i<n;i++)
		if((zbx[i]-zbx[1])*(zby[i]-zby[v3])!=(zbx[i]-zbx[v3])*(zby[i]-zby[1]))
			v01.push_back(i);
	if(v01.size()<=2){
		printf("YES");
		return 0;
	}
	for(int i=2;i<v01.size();i++)
		if((zbx[v01[i]]-zbx[v01[0]])*(zby[v01[i]]-zby[v01[1]])!=
			(zbx[v01[i]]-zbx[v01[1]])*(zby[v01[i]]-zby[v01[0]]))
			ok=0;
	if(ok){
		printf("YES");
		return 0;
	}
	printf("NO");
}