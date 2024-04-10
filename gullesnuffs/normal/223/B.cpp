#include <stdio.h>

using namespace std;

char s[200200], t[200200];
int first[200200], last[200200];

struct Fenwick{
    int n[200200];
    Fenwick(){
        for(int i=0; i < 200200; ++i)
            n[i]=0;
    }
    void add(int p, int v){
        if(p > 200199)
            return;
        n[p] += v;
        add(p|(p+1), v);
    }
    int get(int a, int b){
        if(a == -1){
            int s=0;
            while(b >= 0){
                s += n[b];
                b=(b&(b+1))-1;
            }
            return s;
        }
        return get(-1, b)-get(-1, a);
    }
}fen[30];

int main()
{
    scanf("%s%s", s, t);
    for(int i=0; t[i]; ++i)
        fen[t[i]-'a'].add(i, 1);
    int f=0, j=-1;
    for(int i=0; s[i]; ++i){
        first[i]=f;
        if(t[f+1] && s[i] == t[f]){
            ++f;
        }
        j=i;
    }
    int l;
    for(l=0; t[l]; ++l);
    --l;
    for(int i=j; i >= 0; --i){
        last[i]=l;
        if(l > 0 && s[i] == t[l]){
            --l;
        }
    }
    bool ok=1;
    for(int i=0; s[i]; ++i){
        if(last[i] > first[i] || fen[s[i]-'a'].get(last[i]-1, first[i]) == 0)
            ok=0;
    }
    printf(ok?"Yes":"No");
    return 0;
}