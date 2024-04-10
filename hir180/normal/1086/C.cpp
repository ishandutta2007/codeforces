#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int t;
int k;
char s[1000005],a[1000005],b[1000005];
int ch[32],used[32];
int main(){
    scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&k);
		rep(j,32) ch[j] = -1,used[j] = 0;
		scanf("%s%s%s",&s,&a,&b);
		int n = strlen(s);
		//
		bool bad = 0;
		bool pre = 0,nxt = 0;
		for(int i=0;i<n;i++){
			int L = (a[i]-'a');
			int R = (b[i]-'a');
			if(ch[s[i]-'a'] != -1){
				if(!pre){
					if(ch[s[i]-'a'] < L) {
						bad = 1; goto fail;
					}
					else if(ch[s[i]-'a'] > L){
						pre = 1;
					}
				}
				if(!nxt){
					if(ch[s[i]-'a'] > R) {
						bad = 1; goto fail;
					}
					else if(ch[s[i]-'a'] < R){
						nxt = 1;
					}
				}
			}
			else{
				vector<int>vec;
				for(int x=L;x<k;x++){
					if(used[x]) continue;
					if(!nxt && x > R) continue;
					if(!nxt){
						if(L<x && x<R){
							//ok!
							ch[s[i]-'a'] = x;
							used[x] = 1; goto nxtt;
						}
						else vec.pb(x);
					}
					else{
						if(L < x){
							//ok!
							ch[s[i]-'a'] = x;
							used[x] = 1; goto nxtt;
						}
						else vec.pb(x);
					}
				}
				if(vec.size() == 0){
					bad = 1;
					goto fail;
				}
				else{
					ch[s[i]-'a'] = vec[0];
					used[vec[0]] = 1;
				}
				nxtt:;
				if(!pre){
					if(ch[s[i]-'a'] < L) {
						bad = 1; goto fail;
					}
					else if(ch[s[i]-'a'] > L){
						pre = 1;
					}
				}
				if(!nxt){
					if(ch[s[i]-'a'] > R) {
						bad = 1; goto fail;
					}
					else if(ch[s[i]-'a'] < R){
						nxt = 1;
					}
				}
			}
			if(pre && nxt) break;
		}
		if(bad) goto fail;
		for(int j=0;j<k;j++){
			if(ch[j] == -1){
				for(int w=0;w<k;w++){
					if(used[w] == false){
						ch[j] = w;
						used[w] = 1; break;
					}
				}
			}
		}
		puts("YES");
		for(int j=0;j<k;j++) printf("%c",('a'+ch[j]));
		puts("");
		continue;
		fail:;
		
		//
		rep(j,32) ch[j] = -1,used[j] = 0;
		bad = 0;
		pre = 0,nxt = 0;
		for(int i=0;i<n;i++){
			int L = (a[i]-'a');
			int R = (b[i]-'a');
			if(ch[s[i]-'a'] != -1){
				if(!pre){
					if(ch[s[i]-'a'] < L) {
						bad = 1; goto fail2;
					}
					else if(ch[s[i]-'a'] > L){
						pre = 1;
					}
				}
				if(!nxt){
					if(ch[s[i]-'a'] > R) {
						bad = 1; goto fail2;
					}
					else if(ch[s[i]-'a'] < R){
						nxt = 1;
					}
				}
			}
			else{
				vector<int>vec;
				for(int x=0;x<=R;x++){
					if(used[x]) continue;
					if(!pre && x < L) continue;
					if(!pre){
						if(L<x && x<R){
							//ok!
							ch[s[i]-'a'] = x;
							used[x] = 1; goto nxtt2;
						}
						else vec.pb(x);
					}
					else{
						if(R > x){
							//ok!
							ch[s[i]-'a'] = x;
							used[x] = 1; goto nxtt2;
						}
						else vec.pb(x);
					}
				}
				if(vec.size() == 0){
					bad = 1;
					goto fail2;
				}
				else{
					ch[s[i]-'a'] = vec[vec.size()-1];
					used[vec[vec.size()-1]] = 1;
				}
				nxtt2:;
				if(!pre){
					if(ch[s[i]-'a'] < L) {
						bad = 1; goto fail2;
					}
					else if(ch[s[i]-'a'] > L){
						pre = 1;
					}
				}
				if(!nxt){
					if(ch[s[i]-'a'] > R) {
						bad = 1; goto fail2;
					}
					else if(ch[s[i]-'a'] < R){
						nxt = 1;
					}
				}
			}
			if(pre && nxt) break;
		}
		if(bad) goto fail2;
		for(int j=0;j<k;j++){
			if(ch[j] == -1){
				for(int w=0;w<k;w++){
					if(used[w] == false){
						ch[j] = w;
						used[w] = 1; break;
					}
				}
			}
		}
		puts("YES");
		for(int j=0;j<k;j++) printf("%c",('a'+ch[j]));
		puts("");
		continue;
		fail2:;
		puts("NO");
	}
}