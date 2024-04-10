#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

vector<vector<int> > arr;
int n, m;

int calcRow(int row, int a, int b){
	int ret = 0;
	for(int i = 0; i < m; i++){
		if(i%2 == 0 && arr[row][i] != a){
			ret++;
		}
		if(i%2 == 1 && arr[row][i] != b){
			ret++;
		}
	}
	return ret;
}

int calcCol(int col, int a, int b){
	int ret = 0;
	for(int i = 0; i < n; i++){
		if(i%2 == 0 && arr[i][col] != a){
			ret++;
		}
		if(i%2 == 1 && arr[i][col] != b){
			ret++;
		}
	}
	return ret;
}

pair<int,pair<int, int> > calcBestRow(){
	int cost = INT_MAX;
	pair<int,int> ans;
	int a, b, c, d;
	for(a = 0; a < 4; a++){
		for(b = a+1; b < 4; b++){
			int tmp = 0;
			for(c = 0; c < 4; c++){
				if(c != a && c != b)break;
			}
			for(d = 0; d < 4; d++){
				if(d != a && d != b && d != c)break;
			}
			for(int i = 0; i < n; i++){
				if(i%2 == 0){
					tmp += min(calcRow(i, a, b), calcRow(i, b, a));
				}else{
					tmp += min(calcRow(i, c, d), calcRow(i, d, c));
				}
			}
			if(tmp < cost){
				cost = tmp;
				ans = {a, b};
			}
		}
	}
	return {cost, ans};
}

pair<int,pair<int, int> > calcBestCol(){
	int cost = INT_MAX;
	pair<int,int> ans;
	int a, b, c, d;
	for(a = 0; a < 4; a++){
		for(b = a+1; b < 4; b++){
			int tmp = 0;
			for(c = 0; c < 4; c++){
				if(c != a && c != b)break;
			}
			for(d = 0; d < 4; d++){
				if(d != a && d != b && d != c)break;
			}
			for(int i = 0; i < m; i++){
				if(i%2 == 0){
					tmp += min(calcCol(i, a, b), calcCol(i, b, a));
				}else{
					tmp += min(calcCol(i, c, d), calcCol(i, d, c));
				}
			}
			if(tmp < cost){
				cost = tmp;
				ans = {a, b};
			}
		}
	}
	return {cost, ans};
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    arr.resize(n, vector<int>(m));
    string s;
    for(int i = 0; i < n; i++){
    	cin>>s;
    	for(int j = 0; j < m; j++){
    		if(s[j] == 'A')arr[i][j] = 0;
    		else if(s[j] == 'G')arr[i][j] = 1;
    		else if(s[j] == 'T')arr[i][j] = 2;
    		else arr[i][j] = 3;
    	}
    }

    pair<int, pair<int,int> > x = calcBestRow();
    pair<int, pair<int,int> > y = calcBestCol();
    if(x.first < y.first){
    	int a, b, c, d;
    	a = x.second.first, b = x.second.second;
    	for(c = 0; c < 4; c++){
			if(c != a && c != b)break;
		}
		for(d = 0; d < 4; d++){
			if(d != a && d != b && d != c)break;
		}
		for(int i = 0; i < n; i++){
			if(i%2 == 0){
				if(calcRow(i, a, b) < calcRow(i, b, a)){
					for(int j = 0; j < m; j++){
						if(j%2 == 0)arr[i][j] = a;
						else arr[i][j] = b;
					}
				}else{
					for(int j = 0; j < m; j++){
						if(j%2 == 0)arr[i][j] = b;
						else arr[i][j] = a;
					}
				}
			}else{
				if(calcRow(i, c, d) < calcRow(i, d, c)){
					for(int j = 0; j < m; j++){
						if(j%2 == 0)arr[i][j] = c;
						else arr[i][j] = d;
					}
				}else{
					for(int j = 0; j < m; j++){
						if(j%2 == 0)arr[i][j] = d;
						else arr[i][j] = c;
					}
				}
			}
		}
    }else{
    	int a, b, c, d;
    	a = y.second.first, b = y.second.second;
    	for(c = 0; c < 4; c++){
			if(c != a && c != b)break;
		}
		for(d = 0; d < 4; d++){
			if(d != a && d != b && d != c)break;
		}
		for(int i = 0; i < m; i++){
			if(i%2 == 0){
				if(calcCol(i, a, b) < calcCol(i, b, a)){
					for(int j = 0; j < n; j++){
						if(j%2 == 0)arr[j][i] = a;
						else arr[j][i] = b;
					}
				}else{
					for(int j = 0; j < n; j++){
						if(j%2 == 0)arr[j][i] = b;
						else arr[j][i] = a;
					}
				}
			}else{
				if(calcCol(i, c, d) < calcCol(i, d, c)){
					for(int j = 0; j < n; j++){
						if(j%2 == 0)arr[j][i] = c;
						else arr[j][i] = d;
					}
				}else{
					for(int j = 0; j < n; j++){
						if(j%2 == 0)arr[j][i] = d;
						else arr[j][i] = c;
					}
				}
			}
		}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(arr[i][j] == 0)cout<<'A';
    		else if(arr[i][j] == 1)cout<<'G';
    		else if(arr[i][j] == 2)cout<<'T';
    		else cout<<'C';
    	}
    	cout<<endl;
    }

}