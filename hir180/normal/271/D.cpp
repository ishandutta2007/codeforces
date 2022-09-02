#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int rui[1505]={};
bool ok[27]={};
char str[1505];
vector<int>vec[27];
int k;
int main(){
	scanf("%s",str);
	int leng=strlen(str);
	string st;
	cin >> st;
	for(int i=0;i<26;i++){
		if(st[i]=='0'){
			ok[i]=true;
		}
	}
	scanf("%d",&k);
	for(int i=1;i<=leng;i++){
		if(ok[str[i-1]-'a']){
			rui[i]=rui[i-1]+1;
		}
		else{
			rui[i]=rui[i-1];
		}
	}
	int counter=0;
	for(int i=0;i<leng;i++){
		for(int j=i+1;j<=leng;j++){
			if(rui[j]-rui[i]<=k){
				counter++;
			}
		}
	}
	for(int i=0;i<leng;i++){
		vec[str[i]-'a'].pb(i);
	}
	for(int i=0;i<26;i++){
		string sw[1505];
		int num[26]={};
		for(int j=0;j<vec[i].size() && rui[vec[i][j]+1]-rui[vec[i][j]]<=k;j++){
			num[str[vec[i][j]]-'a']++;
			sw[j]='a'+i;
		}
		for(int i=0;i<26;i++){
			counter-=max(0,num[i]-1);
		}
		int now=1;
		while(1){
			map<string,int>ma; ma.clear();
			for(int j=0;j<vec[i].size();j++){
				if(vec[i][j]>=now && rui[vec[i][j]+1]-rui[vec[i][j]-now]<=k){
					sw[j]+=str[vec[i][j]-now];
					ma[sw[j]]++;
				}
			}
			map<string,int>::iterator ite; int e=counter;
			for(ite=ma.begin();ite!=ma.end();++ite){
				counter-=max(0,ite->second-1);
			} if(e==counter) break;
			now++;
		}
	}
	printf("%d\n",counter);
	return 0;
}