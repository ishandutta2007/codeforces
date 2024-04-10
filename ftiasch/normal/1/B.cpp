// Codeforces Beta Round #1
// Problem B -- Spreadsheets
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int n;
char str[100];

bool get_type(char *str)
{
  if(str[0] != 'R')
    return true;
  if(str[1] < '0' || str[1] > '9')
    return true;
  for(int i = 2; i < strlen(str); ++ i)
    if(str[i] == 'C')
      return false;
  return true;
}

int str2int(char *str)
{
  int num = 0, tmp = 1;
  for(int i = 1; i < strlen(str); ++ i)
    tmp *= 26, num += tmp;
  tmp = 1;
  for(int i = strlen(str) - 1; i >= 0; -- i)
    num += (str[i] - 'A') * tmp, tmp *= 26;
  return num + 1;
}

char* int2str(int num)
{
  num --;
  int len = 1, tmp = 1;
  for(; tmp * 26 <= num; len ++, tmp *= 26, num -= tmp);
  char *str = new char[100];
  str[len] = '\0';
  for(int i = len - 1; i >= 0; -- i)
    str[i] = 'A' + num % 26, num /= 26;
  return str;
}

char* copy(char *ori, int pos, int len)
{
  char *str = new char[100];
  for(int i = 0; i < len; ++ i)
    str[i] = ori[pos + i];
  str[len] = '\0';
  return str;
}

void AtoB(char *str)
{
  for(int i = 0; i < strlen(str); ++ i)
    if('0' <= str[i] && str[i] <= '9')
    {
      printf("R%sC%d\n", copy(str, i, strlen(str) - i), str2int(copy(str, 0, i)));
      return;
    }
}

void BtoA(char *str)
{
  for(int i = 0; i < strlen(str); ++ i)
    if(str[i] == 'C')
    {
      printf("%s%s\n", int2str(atoi(copy(str, i + 1, strlen(str) - i - 1))), copy(str, 1, i - 1));
      return;
    }
}

int main()
{
  scanf("%d", &n);
  for(int i = 0; i < n; ++ i)
  {
    scanf("%s", str);
    if(get_type(str))
      AtoB(str);
    else
      BtoA(str);
  }
  return 0;
}