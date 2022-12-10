#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k,t[20][20],tt[20][20];
const int MOD=1000000000+7;
main(){
	scanf("%d %d %d",&n,&m,&k);
	if(n+m-1>k){
		puts("0");
		return 0;
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&t[i][j]);
	if(n==1&&m==1){
		printf("%d\n",t[0][0]?1:k);
		return 0;
	}
	if(n<m){
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)tt[j][i]=t[i][j];
		swap(n,m);
		memcpy(t,tt,sizeof(t));
	}
	bool seen[20]={};
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)seen[t[i][j]]=true;
	int first,pos=1,last,cnt=0;
	for(int i=1;i<=k;i++)cnt+=!seen[i];
	if(t[0][0])first=t[0][0];else{
		while(pos<=k&&seen[pos])++pos;
		if(pos>k){
			puts("0");
			return 0;
		}
		first=pos;
		++pos;
	}
	if(t[n-1][m-1])last=t[n-1][m-1];else{
		while(pos<=k&&seen[pos])++pos;
		if(pos>k){
			puts("0");
			return 0;
		}
		last=pos;
		++pos;
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(i+j&&t[i][j]==first||i+j!=n+m-2&&t[i][j]==last){
		puts("0");
		return 0;
	}
	typedef vector<char> vi;
	typedef pair<long long,int> state;
	vector<state> s,ss;
	long long code=0;
	for(int i=0;i<k;i++)code=code*16+m;
	s.push_back(state(code,1));
  for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(i+j&&i+j!=n+m-2){
		ss.clear();
//		cout<<s.size()<<endl;
		for(int z=0;z<s.size();z++){
			state &st=s[z];
			int avail=0;
			for(int next=1;next<=k;next++)if(next!=first&&(st.first>>4*(next-1))%16==m)avail++;
			if(avail<n-i)continue;
//cout<<st.second<<" ";
//for(int y=0;y<st.first.size();y++)cout<<(int)st.first[y]<<",";
//cout<<endl;
			if(t[i][j]){
				if((st.first>>4*(t[i][j]-1))%16>j){
					state state2=st;
					state2.first&=~(15LL<<4*(t[i][j]-1));
					state2.first|=(long long)j<<4*(t[i][j]-1);
//					state2.first[t[i][j]-1]=j;
					ss.push_back(state2);
				}
			}else for(int next=1;next<=k;next++)if(next!=first&&next!=last&&(st.first>>4*(next-1))%16>j){
			  state state2=st;
			  state2.first&=~(15LL<<4*(next-1));
				state2.first|=(long long)j<<4*(next-1);
//				state2.first[next-1]=j;
				ss.push_back(state2);
			}
		}
		sort(ss.begin(),ss.end());
		s.clear();
		for(int z=0;z<ss.size();z++){
			if(!s.empty()&&s.back().first==ss[z].first){
				s.back().second+=ss[z].second;
				if(s.back().second>=MOD)s.back().second-=MOD;
			}else{
				s.push_back(ss[z]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<s.size();i++)ans=(ans+s[i].second)%MOD;
	if(!t[0][0]&&!t[n-1][m-1]){
		ans=(long long)cnt*(cnt-1)*ans%MOD;
	}else if(!t[0][0]||!t[n-1][m-1]){
		ans=(long long)cnt*ans%MOD;
	}
	printf("%d\n",ans);
}