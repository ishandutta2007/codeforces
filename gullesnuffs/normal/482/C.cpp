#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

//vector<vector<char> > classes[(1<<20)];
char classes[1<<20][55];
char nex[1<<20][55];
char classLast[1<<20][55];
char classStart[1<<20][55];
char classN[1<<20];
int n;
int len;
char s[55][25];
char cs[55];
char singleN[1<<20];
double dp[1<<20];
bool vis[1<<20];
int lastI[400], lastL[400], lastO[400];

double rec(int state){
	if(vis[state])
		return dp[state];
	if(!singleN[state])
		return 0;
	vis[state]=1;
	double ret=0;
	int num=0;
	for(int i=0; i < len; ++i){
		if(state&(1<<i))
			continue;
		++num;
		int j=state|(1<<i);
		double prod=(singleN[j]+.0)/singleN[state];
		ret += 1+prod*rec(j);
	}
	ret /= num;
	dp[state]=ret;
	return ret;
}

int main(){
	scanf("%d", &n);
	//classes[0].push_back(vector<char>());
	classN[0]=1;
	rep(i,0,n){
		scanf("%s", s[i]);
		//classes[0][0].push_back(i);
		classes[0][i]=i;
		nex[0][i]=i+1;
	}
	if(n == 1){
		puts("0.000000000");
		return 0;
	}
	classLast[0][0]=n-1;
	classStart[0][0]=0;
	
	len=strlen(s[0]);
	singleN[0]=n;
	rep(i,1,1<<len){
		int j=__builtin_ctz(i);
		int k=i^(1<<j);
		int elN=0;
		for(int l=0; l < classN[k]; ++l){
		//for(int l=0; l < classes[k].size(); ++l){
			//if(classes[k][l].size() == 1)
			//	continue;
			if(classStart[k][l] == classLast[k][l])
				continue;
			for(int m=classStart[k][l]; ; m=nex[k][m]){
			//for(int m=0; m < classes[k][l].size(); ++m){
				//int curm=classes[k][l][m];
				int curm=classes[k][m];
				int mys=s[curm][j];
				mys += 128;
				classes[i][elN++]=curm;
				if(lastL[mys] == l && lastI[mys] == i){
					//classes[i][lastO[mys]].push_back(curm);
					int L=lastO[mys];
					if(classStart[i][L] == classLast[i][L])
						++singleN[i];
					++singleN[i];
					nex[i][classLast[i][L]]=elN-1;
					classLast[i][L]=elN-1;
				}
				else{
				/*for(int o=st; o < classes[i].size(); ++o){
					if(s[curm][j] == cs[o]){
						classes[i][o].push_back(curm);
						ok=1;
						break;
					}
				}
				if(!ok){*/
					//cs[classes[i].size()]=s[curm][j];
					lastL[mys]=l;
					lastI[mys]=i;
					lastO[mys]=classN[i];//classes[i].size();
					//classes[i].push_back(vector<char>());
					//classes[i][classes[i].size()-1].push_back(curm);
					classStart[i][classN[i]]=elN-1;
					classLast[i][classN[i]]=elN-1;
					classN[i]++;
				}
				if(m == classLast[k][l])
					break;
			}
		}
		/*rep(j,0,classes[i].size()){
			if(classes[i][j].size() > 1)
				singleN[i] += classes[i][j].size();
		}*/
	}
	printf("%.10lf\n", rec(0));
}