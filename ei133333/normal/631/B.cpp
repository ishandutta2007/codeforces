#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int yoko[5000], yokoidx[5000];
int tate[5000], tateidx[5000];
int main()
{
  int W, H, K;
  cin >> H >> W >> K;
  for(int i = 1; i <= K; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    --B;
    if(A == 1) {
      yoko[B] = C;
      yokoidx[B] = i;
    } else {
      tate[B] = C;
      tateidx[B] = i;
    }
  }

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(j > 0) cout << " ";
      if(yokoidx[i] < tateidx[j]) {
        cout << tate[j];
      } else {
        cout << yoko[i];
      }
    }
    cout << endl;
  }
}