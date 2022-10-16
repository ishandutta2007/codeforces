#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

/*char buffer[SIZE];
int pointer = SIZE;

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}*/

bool Check(long long n, long long d, long long k) {
    if (n - d * k * (k - 1) / 2 > (k - 1) * d)
        return true;
    return false;
}

#define dim (1<<21)
#define margin 100

char buffer[dim];
char* position;

void initialize(){
  position=buffer;
}

void dump(){
  *position=0;
  printf("%s",buffer);
  initialize();
}

void print(long long number){
  char* start=position;
  while(number>0){
    *position=number%10+'0';
    number/=10;
    position++;
  }
  reverse(start,position);
  if(position-buffer+margin > dim)
      dump();
}

void print(char ch){
  *position=ch;
  position++;
  if(position-buffer+margin > dim)
    dump();
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long n, k, answer = 0;
    scanf("%I64d%I64d", &n, &k);
    if (k == 1) {
        printf("%I64d\n", n);
        return 0;
    }
    long long big = 1;
    while ((big + 1) * (big + 2) / 2 <= n)
        big++;
    if (k > big) {
        printf("-1\n");
        return 0;
    }
    big = n;
    if (k * (k - 1) / 2 >= 1e8) {
        big = 1;
        while ((big + 1) * k * (k - 1) / 2 <= n)
            big++;
    }
    for (long long d = 1; d * d <= n; d++)
        if (n % d == 0) {
            if (d <= big && Check(n, d, k))
                answer = max(answer, d);
            if (n / d <= big && Check(n, n / d, k))
                answer = max(answer, n / d);
        }
    if (!answer) {
        printf("-1\n");
        return 0;
    }
    for (long long i = 1; i < k; i++) {
        printf("%I64d ", answer * i);
        n -= answer * i;
    }
    printf("%I64d\n", n);
    return 0;
}