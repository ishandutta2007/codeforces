
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int maxn = 1000000 + 5;

namespace pam {
int sz, tot, last;
int ch[maxn][26], len[maxn], fail[maxn];
pii f[maxn];
int ok[maxn],h[maxn];
int rm[maxn],res=0,now=0;
char s[maxn];

int node(int l) { 
  sz++;
  memset(ch[sz], 0, sizeof(ch[sz]));
  len[sz] = l;
  fail[sz] = 0;
  ok[sz]=1;
  return sz;
}

void clear() { 
  sz = -1;
  last = 0;
  s[tot = 0] = '$';
  node(0);
  node(-1);
  ok[0]=ok[1]=0;
  fail[0] = 1;
}

int getfail(int x) { 
  while (s[tot - len[x] - 1] != s[tot] || tot-len[x]-1<=now){
    x = fail[x];
    if(x!=0&&x!=1){
      int tail = tot-len[x];
      h[x]=tail;
      rm[tail]=x;
    }
  }
  return x;
}

void insert(char c) {  
  s[++tot] = c;
  int now = getfail(last);
  if (!ch[now][c - 'a']) {
    int x = node(len[now] + 2);
    fail[x] = ch[getfail(fail[now])][c - 'a'];
    ch[now][c - 'a'] = x;
    f[x]=mp(now,c-'a');
   // printf("%d %d\n",now,x);
    res++;
  }
  last = ch[now][c - 'a'];

  h[last]=tot-len[last]+1;
  rm[tot-len[last]+1]=last;
  //  printf("update %d %d\n",last,h[last]);
}
void erase(){
    now++;
    s[now]='$';
    int needrm=rm[now];
    if(h[needrm]==now&&ok[needrm]){
       // printf("%d\n",needrm);
        res--;
        pii p=f[needrm];
        ok[needrm]=0;
        if(last==needrm)last=fail[last];
        ch[p.x][p.y]=0;
        int tar=fail[needrm];
        int tail=now+len[needrm]-1;
        if(h[tar]<tail-len[tar]+1&&tar!=0&&tar!=1){
            h[tar]=tail-len[tar]+1;
            if(len[rm[tail-len[tar]+1]]<len[tar])
            rm[tail-len[tar]+1]=tar;
           // printf("update %d %d\n",tar,tail-len[tar]+1);
        }
    }
}
}  // namespace pam
void solve(int T){
    pam::clear();
    int q;
    scanf("%d",&q);
    while(q--){
        char c[10];
        scanf("%s",c);
        if(c[1]=='u'){
            char c2;
            scanf(" %c",&c2);
            pam::insert(c2);
        }
        else{
            pam::erase();
        }
        printf("%d\n",pam::res);
    }


}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
1 2 3 4
*/