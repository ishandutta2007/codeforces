#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define MAXN 100010
#define MAXL 20
using namespace std;

int n;
char str[MAXN][MAXL];
vector<pair<int,int> > s[MAXN];
map<pair<int,int>,int> S;

void gao(int x){
	for(int i=1;i<=9;i++){
		int temp=0;
		for(int j=i;j<=9;j++){
			temp=temp*10+str[x][j]-'0';
			s[x].push_back(make_pair(temp,j-i+1));
		}
	}
	sort(s[x].begin(),s[x].end());
	for(int i=0;i<s[x].size();i++)
		if(i==0 || s[x][i]!=s[x][i-1])
			S[s[x][i]]++;
}

void output(int v,int l){
	static int temp[30];
	for(int i=1;i<=l;i++){
		temp[i]=v%10;
		v/=10;
	}
	for(int i=l;i>=1;i--)
		putchar(temp[i]+'0');
	puts("");
}

void query(int x){
	int minl=10,minv;
	for(int i=0;i<s[x].size();i++)
		if(i==0 || s[x][i]!=s[x][i-1]){
			if(S[s[x][i]]==1)
				if(s[x][i].second<minl){
					minl=s[x][i].second;
					minv=s[x][i].first;
				}
		}
	output(minv,minl);
}

int main(){
#ifdef DEBUG
	freopen("B.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++)
		gao(i);
	for(int i=1;i<=n;i++)
		query(i);
}