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
int main(){
	int n;
	scanf("%d",&n);
	string str[35];
	for(int i=0;i<n;i++){
		cin >> str[i];
	}
	map<string,int>ma;
	for(int i=0;i<n;i++){
		int ep=str[i].size();
		for(int w=0;w<ep;w++){
			string st="";
			for(int j=w;j<ep;j++){
				st+=str[i][j];
				ma[st]++;
			}
		}
	}
	for(int i=0;i<26;i++){
		string su="";
		su.pb('a'+i);
		if(!ma[su]){
			cout << su << endl;
			return 0;
		}
	}
	for(int i=0;i<26;i++){
		string su="";
		su.pb('a'+i);
		for(int j=0;j<26;j++){
			string sw=su;
			sw.pb('a'+j);
			if(!ma[sw]){
				cout << sw << endl;
				return 0;
			}
		}
	}
	for(int i=0;i<26;i++){
		string su="";
		su.pb('a'+i);
		for(int j=0;j<26;j++){
			su.resize(1);
			su.pb('a'+j);
			for(int k=0;k<26;k++){
				su.resize(2);
				su.pb('a'+k);
				if(!ma[su]){
					cout << su << endl;
					return 0;
				}
			}
		}
	}
	for(int i=0;i<26;i++){
		string su="";
		su.pb('a'+i);
		for(int j=0;j<26;j++){
			su.resize(1);
			su.pb('a'+j);
			for(int k=0;k<26;k++){
				su.resize(2);
				su.pb('a'+k);
				for(int e=0;e<26;e++){
					su.resize(3);
					su.pb(e+'a');
					if(!ma[su]){
						cout << su << endl;
						return 0;
					}
				}
			}
		}
	}
}