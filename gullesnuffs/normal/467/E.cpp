#include <bits/stdc++.h>

using namespace std;

int a[500005];
int skip[500005];
map<int, int> last;
map<int, int> S;
int other[500005];
vector<int> ans;
map<int, int> haveN;

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		scanf("%d", a+(i+1));
	for(int i=1; i <= n; ++i){
		haveN[a[i]]++;
		if(haveN[a[i]] >= 4){
				int y=a[i];
				for(int m=0; m < 4; ++m){
				ans.push_back(y);}
				last.clear();
				S.clear();
				haveN.clear();
				continue;
		}
		skip[i]=i+1;
		if(last[a[i]] == 0){
			last[a[i]]=i;
		}
		else{
			if(S.find(a[i]) != S.end()){
				int x=other[S[a[i]]], y=a[i];
				for(int m=0; m < 2; ++m){ans.push_back(x);
				ans.push_back(y);}
				last.clear();
				S.clear();
				haveN.clear();
				continue;
			}
			for(int j=last[a[i]]+1; j < i;){
				if(a[j] == a[i]){
					//skip[last[a[i]]]=j;
				}
				else{
					S[a[j]]=j;
					other[j]=a[i];
				}
				int k=j;
				j=skip[j];
				skip[k]=i;
			}
		}
	}
	printf("%d\n", ans.size());
	for(int i=0; i < ans.size(); ++i){
		printf("%d ", ans[i]);
	}
}