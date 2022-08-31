#include<bits/stdc++.h>
using namespace std;

int N;
vector< int > tree[1000000];
int subtree[100000];
double F[1000000];

int rec(int idx)
{
  subtree[idx] = 1;
  for(int to : tree[idx]) subtree[idx] += rec(to);
  return(subtree[idx]);
}

void calc(int idx, int par = -1)
{
  for(int to : tree[idx]) {
    F[to] = (subtree[idx] - subtree[to] - 1) * 0.5;
    F[to] += F[idx] + 1.0;
    calc(to);
  }
}


int main()
{
  scanf("%d", &N);
  for(int i = 1; i < N; i++) {
    int R;
    scanf("%d", &R);
    tree[--R].push_back(i);
  }
  rec(0);
  F[0] = 1.0;
  calc(0);
  for(int i = 0; i < N; i++) {
    printf("%.10lf ", F[i]);
  }
}