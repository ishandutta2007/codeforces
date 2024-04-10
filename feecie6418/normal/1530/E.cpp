#include<bits/stdc++.h>
using namespace std;
int n,cnt[140];
char str[100005]; 
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=127;i++)cnt[i]=0;
		cin>>str+1,n=strlen(str+1);
		sort(str+1,str+n+1);
		char mn=127;
		for(int i=1;i<=n;i++)mn=min(mn,str[i]);
		for(int i=1;i<=n;i++)cnt[str[i]]++;
		bool ii=0;
		for(int i=1;i<=127;i++){
			if(cnt[i]==1){
				cout<<(char)i,ii=1;
				for(int j=1;j<=n;j++)if(str[j]!=i)cout<<str[j];
				puts("");
				break;
			}
		}
		if(ii)continue;
		if(n-cnt[mn]>=cnt[mn]-2){
			cout<<mn<<mn,cnt[mn]-=2;
			for(int i=1;i<=n;i++){
				if(str[i]!=mn){
					cout<<str[i];
					if(cnt[mn])cnt[mn]--,cout<<mn;
				}
			}
			puts("");
			continue;
		}
		else {
			if(cnt[mn]==n){
				for(int i=1;i<=n;i++)cout<<str[i];
				puts("");
				continue;
			}
			cout<<mn,cnt[mn]--;
			char nxt=127;
			for(int i=1;i<=n;i++)if(str[i]!=mn)nxt=min(nxt,str[i]);
			bool flag=0;
			for(int i=1;i<=n;i++)if(str[i]!=mn&&str[i]!=nxt)flag=1;
			if(flag==0){
				for(int i=1;i<=n;i++)if(str[i]==nxt)cout<<str[i];
				for(int i=1;i<=n;i++)if(str[i]==mn&&cnt[mn])cnt[mn]--,cout<<str[i];
				puts("");
				continue;
			}
			cout<<nxt,cnt[nxt]--;
			for(int i=1;i<=n;i++)if(str[i]==mn&&cnt[mn])cnt[mn]--,cout<<str[i];
			for(int i=1;i<=n;i++)if(str[i]!=mn&&str[i]!=nxt){cout<<str[i],cnt[str[i]]--;break;}
			for(int i=1;i<=n;i++)if(cnt[str[i]])cout<<str[i],cnt[str[i]]--;
			puts("");
		}
	}
}