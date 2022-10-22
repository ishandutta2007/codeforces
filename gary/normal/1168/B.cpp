#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string s;
queue<int> q;
int each[300001];
int main(){
//	freopen("hack.in","r",stdin);
	cin>>s;
	int len=s.length();
	rb(i,1,len) q.push(i);
	rb(i,1,(len-1)/2){
		queue<int> tmp;
		while(!q.empty()){
			int now=q.front();
//			cout<<i<<":"<<now<<endl;
			q.pop();
//			if(){
			if(now+i+i<=len&&s[now-1]==s[now+i-1]&&s[now-1]==s[now+i+i-1]) {
				each[now]=i;
			}	
			else tmp.push(now);
		}
		q=tmp;
	}
	LL res=0;
	int best=INF;
	rl(i,len,1){
//		cout<<each[i]<<" "<<i<<"*"<<best<<endl;
		if(each[i]){
			each[i]=i+each[i]+each[i];
			each[i]=min(each[i],best);
			best=min(best,each[i]);
		}
		else
		{
			each[i]=best;
		}
	}
	rb(i,1,len){
		if(each[i]!=INF){
			res+=len-each[i]+1;
//			cout<<i<<":"<<each[i]<<" ";
		}
	}
//	cout<<endl;
	printf("%I64d\n",res);
	return 0;
}