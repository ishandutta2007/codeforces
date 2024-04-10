#include <bits/stdc++.h>

using namespace std;

int n;
pair<string, string> names[100005];
string allNames[200005];
map<string, int> M;
int p[100005];

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		string f, s;
		cin >> f >> s;
		names[i]=make_pair(f,s);
		allNames[2*i]=f;
		allNames[2*i+1]=s;
	}
	sort(allNames, allNames+2*n);
	for(int i=0; i < 2*n; ++i)
		M[allNames[i]]=i;
	int best=-1;
	for(int i=0; i < n; ++i){
		scanf("%d", p+i);
		--p[i];
		string f=names[p[i]].first, s=names[p[i]].second;
		int Min=min(M[f],M[s]);
		int Max=max(M[f],M[s]);
		if(Min > best)
			best = Min;
		else if(Max > best)
			best = Max;
		else
			best = 1000000;
	}
	puts(best < 1000000 ? "YES" : "NO");
}