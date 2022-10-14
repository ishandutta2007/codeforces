// Codeforces Beta Round #3
// Problem D -- Least Cost Bracket Sequence
#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxN 500000
#define INF 100000000000LL

using namespace std;

char bracket[maxN + 1];
int size, heap[maxN + 1];
bool visit[maxN];
long long answer, change[maxN];

void push(int x)
{
  heap[++ size] = x;
  int i = size;
  while(i > 1)
  {
    if(change[heap[i]] >= change[heap[i >> 1]])break;
    swap(heap[i], heap[i >> 1]); i = i >> 1;
  }  
}

void pop()
{
  size --;
  if(size == 0)
    return;
  heap[1] = heap[size + 1];
  int i = 1;
  while(i <= size)
  {
    int j = i;
    if(i + i <= size && change[heap[i + i]] < change[heap[j]])
      j = i + i;
    if(i + i + 1 <= size && change[heap[i + i + 1]] < change[heap[j]])
      j = i + i + 1;    
    if(i == j)break;
    swap(heap[i], heap[j]); i = j;
  }
}

int main()
{
  scanf("%s", bracket);
  int n = strlen(bracket);
  if(n & 1)
  {
    printf("-1\n");
    return 0;
  }
  answer = 0;
  for(int i = 0; i < n; ++ i)
    if(bracket[i] == '(')
      change[i] = 3 * INF;
    else
    if(bracket[i] == ')')
      answer += 3 * INF, change[i] = -3 * INF;
    else
    {
      int a, b; scanf("%d%d", &a, &b);
      answer += a, change[i] = b - a;
    }
  memset(visit, 0, sizeof(visit));
  size = 0;
  for(int i = n / 2; i > 0; -- i)
  {
    if(i + i < n)
      push(i + i);
    push(i + i - 1);
    answer += change[heap[1]];
    visit[heap[1]] = true;
    pop();
  }
  if(answer > INF)
  {
    printf("-1\n");
    return 0;
  }  
  printf("%I64d\n", answer);  
  for(int i = 0; i < n; ++ i)
    printf(visit[i]? ")": "(");
  printf("\n");
  return 0;
}