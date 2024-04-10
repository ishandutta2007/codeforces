#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
string s,t;
int ranki[19][200001];
vector<pair<int,int> >buc[200002],buc2[200002];
int suff[200001];
int h[200001];
int lcp[200001];
int prefi[200001];
pair<int,int>a[200001];
int l[200001],r[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s >> t;
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	s=' '+s;
	t=' '+t;
	long long ans=0;
	for(int i=1; i<=n ;i++){
		ranki[0][i]=s[i]-96;
	}
	for(int i=1; i<=n ;i++){
		if(t[i]=='0') ans=max(ans,1LL*(n-i+1));
	}
	int tmp=0;
	for(int i=1; (1<<(i-1))<=n ;i++){
		tmp++;
		for(int j=1; j<=n-(1<<(i-1)) ;j++){//put
			buc[ranki[i-1][j+(1<<(i-1))]].push_back(make_pair(ranki[i-1][j],j));
		}
		for(int j=max(1,n-(1<<(i-1))+1); j<=n ;j++){
			buc[0].push_back(make_pair(ranki[i-1][j],j));
		}
		for(int j=0; j<=max(26,n) ;j++){
			for(int k=0; k<buc[j].size() ;k++){
				buc2[buc[j][k].first].push_back(make_pair(j,buc[j][k].second));
			}
			buc[j].clear();
		}
		int ptr=0;
		for(int j=0; j<=max(26,n) ;j++){
			for(int k=0; k<buc2[j].size() ;k++){
				//cout << buc2[j][k].second << ' ' << j << ' ' << buc2[j][k].first << endl;
				ptr++;
				if(k==0 || buc2[j][k-1].first<buc2[j][k].first) ranki[i][buc2[j][k].second]=ptr;
				else ranki[i][buc2[j][k].second]=ranki[i][buc2[j][k-1].second];
			}
			buc2[j].clear();
		}
	}
	for(int i=1; i<=n ;i++){
		h[i]=ranki[tmp][i];
		suff[ranki[tmp][i]]=i;
	}
	for(int i=1; i<=n ;i++){
		lcp[h[i]]=max(0,lcp[h[i-1]]-1);
		int j=suff[h[i]-1];
		while(i+lcp[h[i]]<=n && j+lcp[h[i]]<=n && s[i+lcp[h[i]]]==s[j+lcp[h[i]]]) lcp[h[i]]++;
	}
	for(int i=1; i<=n ;i++){
		prefi[i]=prefi[i-1]+1-(t[suff[i]]-48);
		a[i]=make_pair(lcp[i],i);
	}
	sort(a+1,a+n+1);
	int maxi=0;
	for(int i=n; i>=1 ;i--){
		if(a[i].first==0) break;
		int cur=a[i].second;
		l[cur]=r[cur]=cur;
		if(cur+1<=n && r[cur+1]!=0){
			r[cur]=r[cur+1];
			l[r[cur]]=l[cur];
		}
		if(cur-1>=1 && l[cur-1]!=0){
			l[cur]=l[cur-1];
			r[l[cur]]=r[cur];
		}
		maxi=max(maxi,prefi[r[cur]]-prefi[max(0,l[cur]-2)]);
		ans=max(ans,1LL*maxi*a[i].first);
	}
	cout << ans << endl;
}