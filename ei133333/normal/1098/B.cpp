#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

const string P = "ACGT";

pair< int64, tuple< int, int, int, int, int > > solve(vector< string > &S) {

  int N = S.size();
  int M = (int) S[0].size();

  int tt, aa, bb, cc, dd, ee;

  int64 ret = INF;
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < i; j++) {

      vector< int > Fr{i, j};
      vector< char > Se;
      for(int k = 0; k < 4; k++) {
        if(i != k && j != k) Se.emplace_back(k);
      }

      int64 add = 0;
      for(int k = 0; k < N; k++) {
        int64 latte = 0, malta = 0;
        if(k & 1) {
          for(int l = 0; l < M; l++) {
            latte += S[k][l] != P[Fr[l & 1]];
            malta += S[k][l] != P[Fr[(l + 1) & 1]];
          }
        } else {
          for(int l = 0; l < M; l++) {
            latte += S[k][l] != P[Se[l & 1]];
            malta += S[k][l] != P[Se[(l + 1) & 1]];
          }
        }
        add += min(latte, malta);
      }
      if(add < ret) {
        tt = 0;
        ret = add;
        aa = i;
        bb = j;
      }
    }
  }


  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if(i == j) continue;
      for(int k = 0; k < 4; k++) {
        if(i == k || j == k) continue;
        for(int l = 0; l < 4; l++) {
          if(i == l || j == l || k == l) continue;


          int64 add = 0;

          for(int m = 0; m < M; m += 2) {

            int64 a = 0;

            for(int n = 0; n < N; n++) {
              if(n & 1) {
                a += S[n][m] != P[i];
                a += m + 1 < M ? (S[n][m + 1] != P[j]) : 0;
              } else {
                a += S[n][m] != P[k];
                a += m + 1 < M ? (S[n][m + 1] != P[l]) : 0;
              }
            }


            int64 c = 0;
            for(int n = 0; n < N; n++) {
              if((n + 1) & 1) {
                c += S[n][m] != P[i];
                c += m + 1 < M ? (S[n][m + 1] != P[j]) : 0;
              } else {
                c += S[n][m] != P[k];
                c += m + 1 < M ? (S[n][m + 1] != P[l]) : 0;
              }
            }

            add += min(a, c);
          }
          if(add < ret) {
            tt = 1;
            ret = add;
            aa = i;
            bb = j;
            cc = k;
            dd = l;
          }

        }

      }
    }


  }
  return make_pair(ret, make_tuple(tt, aa, bb, cc, dd));
}


vector< vector< char > > up(vector< string > &S, int tt, int aa, int bb, int cc, int dd) {

  int N = S.size();
  int M = (int) S[0].size();

  vector< vector< char > > mat(N, vector< char >(M));
  if(tt == 0) {
    int i = aa;
    int j = bb;
    vector< int > Fr{i, j};
    vector< char > Se;
    for(int k = 0; k < 4; k++) {
      if(i != k && j != k) Se.emplace_back(k);
    }

    int64 add = 0;
    for(int k = 0; k < N; k++) {
      int64 latte = 0, malta = 0;
      if(k & 1) {
        for(int l = 0; l < M; l++) {
          latte += S[k][l] != P[Fr[l & 1]];
          malta += S[k][l] != P[Fr[(l + 1) & 1]];
        }
      } else {
        for(int l = 0; l < M; l++) {
          latte += S[k][l] != P[Se[l & 1]];
          malta += S[k][l] != P[Se[(l + 1) & 1]];
        }
      }

      if(latte < malta) {
        if(k & 1) {
          for(int l = 0; l < M; l++) {
            mat[k][l] = P[Fr[l & 1]];
          }
        } else {
          for(int l = 0; l < M; l++) {
            mat[k][l] = P[Se[l & 1]];
          }
        }
      } else {

        if(k & 1) {
          for(int l = 0; l < M; l++) {
            mat[k][l] = P[Fr[(l + 1) & 1]];
          }
        } else {
          for(int l = 0; l < M; l++) {
            mat[k][l] = P[Se[(l + 1) & 1]];
          }
        }

      }
    }

  } else {
    int i = aa;
    int j = bb;
    int k = cc;
    int l = dd;

    int64 add = 0;

    vector< vector< char > > mat(N, vector< char >(M));

    for(int m = 0; m < M; m += 2) {

      int64 a = 0;

      for(int n = 0; n < N; n++) {
        if(n & 1) {
          a += S[n][m] != P[i];
          a += m + 1 < M ? (S[n][m + 1] != P[j]) : 0;
        } else {
          a += S[n][m] != P[k];
          a += m + 1 < M ? (S[n][m + 1] != P[l]) : 0;
        }
      }


      int64 c = 0;
      for(int n = 0; n < N; n++) {
        if((n + 1) & 1) {
          c += S[n][m] != P[i];
          c += m + 1 < M ? (S[n][m + 1] != P[j]) : 0;
        } else {
          c += S[n][m] != P[k];
          c += m + 1 < M ? (S[n][m + 1] != P[l]) : 0;
        }
      }

      if(a < c) {


        for(int n = 0; n < N; n++) {
          if(n & 1) {
            mat[n][m] = P[i];
            if(m + 1 < M) mat[n][m + 1] = P[j];
          } else {
            mat[n][m] = P[k];
            if(m + 1 < M) mat[n][m + 1] = P[l];
          }
        }

      } else {

        for(int n = 0; n < N; n++) {
          if((n + 1) & 1) {
            mat[n][m] = P[i];
            if(m + 1 < M) mat[n][m + 1] = P[j];
          } else {
            mat[n][m] = P[k];
            if(m + 1 < M) mat[n][m + 1] = P[l];
          }
        }


      }
    }
  }
  return mat;
}


int main() {
  int N, M;
  cin >> N >> M;
  vector< string > S(N);
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }
  auto ret1 = solve(S);

  vector< string > Q(M, string(N, '*'));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      Q[j][N - i - 1] = S[i][j];
    }
  }
  auto ret2 = solve(Q);


  if(ret1 < ret2) {
    int tt, aa, bb, cc, dd;
    tie(tt, aa, bb, cc, dd) = ret1.second;
    auto mat = up(S, tt, aa, bb, cc, dd);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) cout << mat[i][j];
      cout << endl;
    }
  } else {
    int tt, aa, bb, cc, dd;
    tie(tt, aa, bb, cc, dd) = ret2.second;
    auto mat = up(Q, tt, aa, bb, cc, dd);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) cout << mat[j][N-i-1];
      cout << endl;
    }
  }


}