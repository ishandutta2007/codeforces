#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAX 10000

using namespace std;

char line[MAX];
char s[MAX];
char tag[100];

int S;
vector<int> res;
int pos;

void get(){
  int i,sum=0;
  while(true){
    pos+=2;
    i=0;
    for(;s[pos]!='>';pos++,i++) tag[i]=s[pos];
    tag[i]='\0';
    if(tag[0]=='/'&&tag[2]=='a'){ res.push_back(sum); break; }
    if(tag[1]=='d') sum++;
    if(tag[1]=='a') get();
  }
}

int main(int argc, char *argv[]){
  S=0;
  int i;
  while(scanf("%s",line)!=EOF){for(i=0;line[i]!='\0';i++) s[S++]=line[i]; }
  pos=6;
  get();
  sort(res.begin(),res.end());
  FOR(i,res.size()){ if(i) printf(" "); printf("%d",res[i]); }
  printf("\n");
  return 0;
}