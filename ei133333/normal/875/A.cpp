#include<bits/stdc++.h>

using namespace std;

int mult[] = {100000001, 10000001, 1000001, 100001, 10001, 1001, 101, 11, 2};
int mult2[] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};


int main()
{
  int N;
  cin >> N;


  int fact = 1;
  vector< int > vs;
  for(int i = 0; i < 10; i++) {  // 0
    for(int j = 0; j < 10; j++) { // 1
      for(int k = 0; k < 10; k++) { // 2
        for(int l = 0; l < 10; l++) { // 3
          for(int m = 0; m < 10; m++) { // 4
            for(int n = 0; n < 10; n++) { // 5
              for(int o = 0; o < 10; o++) { // 6
                for(int p = 0; p < 10; p++) { // 7
                  int sum = mult[0] * i + mult[1] * j + mult[2] * k + mult[3] * l + mult[4] * m + mult[5] * n + mult[6] * o + mult[7] * p;
                  sum = N - sum;
                  if(sum < 0 || (sum & 1)) continue;
                  if(sum >= 20) continue;
                  sum >>= 1;
                  vs.push_back(mult2[0] * i + mult2[1] * j + mult2[2] * k + mult2[3] * l + mult2[4] * m + mult2[5] * n + mult2[6] * o + mult2[7] * p + sum);
                }
              }
            }
          }
        }
      }
    }
  }

  sort(begin(vs), end(vs));
  cout << vs.size() << endl;
  for(int i = 0; i < vs.size(); i++) cout << vs[i] << endl;

}