// Codeforces Beta Round #3
// Problem C -- Tic-tac-toe
#include <cstdio>

using namespace std;

char g[4][4];

int cnt(char c)
{
  int s = 0;
  for(int i = 0; i < 3; ++ i)
    for(int j = 0; j < 3; ++ j)
      s += (g[i][j] == c);        
  return s;
}

bool ttt(char c)
{
  for(int i = 0; i < 3; ++ i)
    if(g[i][0] == c && g[i][1] == c && g[i][2] == c)
      return true;
  for(int i = 0; i < 3; ++ i)
    if(g[0][i] == c && g[1][i] == c && g[2][i] == c)
      return true;
  if(g[0][0] == c && g[1][1] == c && g[2][2] == c)
    return true;
  if(g[0][2] == c && g[1][1] == c && g[2][0] == c)
    return true;    
  return false;  
}

int main()
{
  for(int i = 0; i < 3; ++ i)
    scanf("%s", g[i]);
  #define C1 cnt('X')
  #define C2 cnt('0')
  #define W1 ttt('X')
  #define W2 ttt('0')
  if(C1 < C2 || C1 > C2 + 1 || (W1 && W2) || (W1 && C1 == C2) || (W2 && C1 == C2 + 1))
    printf("illegal\n");
  else
  if(W1)
    printf("the first player won\n");
  else
  if(W2)
    printf("the second player won\n");
  else
  if(C1 + C2 == 9)
    printf("draw");
  else
  if(C1 == C2)
    printf("first\n");
  else
    printf("second\n");
  return 0;
}