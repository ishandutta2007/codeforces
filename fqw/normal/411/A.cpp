#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
char s[888]; scanf("%s",s); int n=strlen(s);
#define no {printf("Too weak\n");return 0;}
if(n<5) no;
bool large=false, small=false, digit=false;
for(int i=0; i<n;++i) {
  if(s[i]>='0'&&s[i]<='9')digit=true;
  if(s[i]>='a'&&s[i]<='z')small=true;
  if(s[i]>='A'&&s[i]<='Z')large=true;
}
if(large&&small&&digit)printf("Correct\n"); else no;
}