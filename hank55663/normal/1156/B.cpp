#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int cnt[26];
		fill(cnt,cnt+26,0);
		char c[105];
		scanf("%s",c);
		vector<int> v;
		for(int i = 0;c[i]!=0;i++){
			cnt[c[i]-'a']++;
			if(cnt[c[i]-'a']==1){
				v.pb(c[i]-'a');
			}
		}
		sort(v.begin(),v.end());
		if(v.back()-v[0]<=2&&v.size()!=1&&!(v.size()==2&&v.back()-v[0]==2)){
			printf("No answer\n");
		}
		else{
			if(v.size()!=3){
				for(int i = 1;i<v.size();i+=2){
					while(cnt[v[i]]){
						printf("%c",v[i]+'a');
						cnt[v[i]]--;
					}
				}
				for(int i = 0;i<v.size();i+=2){
					while(cnt[v[i]]){
						printf("%c",v[i]+'a');
						cnt[v[i]]--;
					}
				}
			}
			else{
				if(v[0]+1!=v[1])swap(v[0],v[1]);
				else swap(v[1],v[2]);
				for(auto it:v){
					while(cnt[it]){
						printf("%c",it+'a');
						cnt[it]--;
					}
				}
			}
			printf("\n");
		}
	}
}