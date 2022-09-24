#include<bits/stdc++.h>
using namespace std;
int n,v[100005],c[100005],l[100005],r[100005],s[100005],tof[100005];
int o,cnt,anss=0,ansp=0;
map<pair<int,int>,int> f,tmp;
vector<int> ans;
int main(){
	cin>>n;
	for(int i=0;i<=200000;i++)f[make_pair(0,i)]=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&v[i],&c[i],&l[i],&r[i]);
		if(!f.count(make_pair(l[i],r[i]+c[i])))continue;
		s[i]=f[make_pair(l[i],r[i]+c[i])]+v[i];
		if(s[i]>f[make_pair(l[i]+c[i],r[i])])f[make_pair(l[i]+c[i],r[i])]=s[i],tmp[make_pair(l[i]+c[i],r[i])]=i;
		if(!r[i]&&s[i]>anss)anss=s[i],ansp=i;
		tof[i]=tmp[make_pair(l[i],r[i]+c[i])];
	}
	if(anss==0)return puts("0"),0;
	while(ansp)ans.push_back(ansp),ansp=tof[ansp];
	reverse(ans.begin(),ans.end()),cout<<ans.size()<<endl;
	for(int i:ans)cout<<i<<' ';
    return 0;
}