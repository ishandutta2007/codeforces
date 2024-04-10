#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,cnt[26];
string s;
void Solve(){
	cin>>s;
	int n=s.length();
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;++i)++cnt[s[i]-'a'];
	int type=0,one=-1,mn=-1;
	for(int i=25;i>=0;--i){
		if(cnt[i]>=1)++type,mn=i;
		if(cnt[i]==1)one=i;
	}
	if(type==1){
		cout<<s<<endl;
		return;
	}
	if(~one){
		s="";
		s+=one+'a';
		for(int i=0;i<26;++i){
			if(i==one)continue;
			while(cnt[i]--)s+=i+'a';
		}
		cout<<s<<endl;
		return;	
	}
	if(cnt[mn]<=n/2+1){
		--cnt[mn];
		s="";
		s+=mn+'a';
		for(int i=0;i<26;++i){
			if(i==mn)continue;
			while(cnt[i]--){
				if(cnt[mn])--cnt[mn],s+=mn+'a';
				s+=i+'a';
			}
		}
		while(cnt[mn]--)s+=mn+'a';
		cout<<s<<endl;
		return;
	}
	s="";
	s+=mn+'a';
	--cnt[mn];
	int se=-1,th=-1;
	for(int i=0;i<26;++i){
		if(i==mn||!cnt[i])continue;
		if(!~se)se=i;
		else if(!~th)th=i;
	}
	if(type>2){
		s+=se+'a';--cnt[se];
		while(cnt[mn])s+=mn+'a',--cnt[mn];
		s+=th+'a';--cnt[th];
		for(int i=0;i<26;++i){
			while(cnt[i]--)s+=i+'a';
		}
	}
	else{
		while(cnt[se]--)s+=se+'a';
		while(cnt[mn]--)s+=mn+'a';
	}
	cout<<s<<endl;
}
int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}