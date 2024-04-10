#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
deque<pr> q,a,b;
vector<pr> ans;
int n,m,rev;
char s[200005],t[200005];
void Do(int l1,int l2){
	//cout<<"Do:"<<l1<<' '<<l2<<'\n';
	vector<pr> t1,t2;
	int s1=0,s2=0;
	for(int i=1;i<=l1;i++)s1+=a.front().second,t1.push_back(a.front()),a.pop_front();
	for(int i=1;i<=l2;i++)s2+=b.front().second,t2.push_back(b.front()),b.pop_front();
	for(int i=l2-1;i>=0;i--){
		if(!a.size()||a.front().first!=t2[i].first)a.push_front(t2[i]);
		else {
			t2[i].second+=a.front().second;
			a.pop_front(),a.push_front(t2[i]);
		}
	}
	for(int i=l1-1;i>=0;i--){
		if(!b.size()||b.front().first!=t1[i].first)b.push_front(t1[i]);
		else {
			t1[i].second+=b.front().second;
			b.pop_front(),b.push_front(t1[i]);
		}
	}
	if(rev)swap(s1,s2);
	ans.push_back(pr(s1,s2));
}
int main(){
	scanf("%s%s",s+1,t+1),rev=0;
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&s[j+1]==s[i])j++;
		a.push_back(pr(s[i]-'a',j-i+1));
	}
	for(int i=1,j;i<=m;i=j+1){
		j=i;
		while(j<m&&t[j+1]==t[i])j++;
		b.push_back(pr(t[i]-'a',j-i+1));
	}
	while(a.size()>1||b.size()>1){
		//cout<<a.size()<<' '<<b.size()<<'\n';
		if(a.size()>b.size())swap(a,b),rev^=1;
		if(a.size()==1){
			if(a.front().first==b.front().first){
				Do(0,(b.size()-1)/4*2+1);
			}
			else {
				Do(1,b.size()/4*2+1);
			}
		}
		else if(a.size()==2&&b.size()==2&&a.front().first==b.front().first){
			Do(0,1);
		}
		else if(a.front().first==b.front().first)Do(1,(b.size()-a.size())/4*2+2);
		else Do(1,(b.size()-a.size()+1)/4*2+1);
//		for(pr i:a)printf("(%c,%d)",i.first+'a',i.second);
//		puts("");
//		for(pr i:b)printf("(%c,%d)",i.first+'a',i.second);
//		puts("");
	}
	cout<<ans.size()<<'\n';
	for(pr i:ans)cout<<i.first<<' '<<i.second<<'\n';
}