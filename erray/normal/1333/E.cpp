#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
#define pb emplace_back
#define mp make_pair 
#define st first 
#define nd second 
#define all(v) v.begin(),v.end()
#define umap unordered_map
#define L nd<<1
#define R (L)|1
#define mid ((s + e)>>1)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int mat[505][505];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> n;
  int tn = n;
  if(n < 3){
  	cout << -1;
  	return 0;
  }
  int x = 1, y = 1;
  int req = n*n - 3*3;
  if(n%2){
  	x = n;
  	y = n;
  }
  int num = 2;
  mat[x][y] = 1;
  while(n > 3){
  	if(n % 2){
  		for(int i = 1; i < n; i++){
  			y--;
  			mat[x][y] = num++; 
  		}
  		for(int i = 1; i < n; i++){
  			x--;
  			mat[x][y] = num++;
  		}	
  		y++;
  		mat[x][y] = num++;
  	}
  	else {
  		for(int i = 1; i < n; i++){
  			x++;
  			mat[x][y] = num++; 
  		}
  		for(int i = 1; i < n; i++){
  			y++;
  			mat[x][y] = num++;
  		}	
  		x--;
  		mat[x][y] = num++;
  	}
  	n--;
  }
  n = tn;
  num-=2;
  int ans[3][3]={8, 5, 3,
                 6, 2, 4,
                 7, 9, 1};
  for(int i = 0; i < 3; i++){
  	for(int j = 0; j < 3 ;j++){
  		mat[i + 1][n - 2 + j] = ans[i][j] + num;
		}
  }
  for(int i = 1; i <= n; i++){for(int j = 1; j <= n; j++)cout << mat[i][j] << " ";cout << ln;}
}