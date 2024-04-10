#include <list>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

#define forall(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

typedef long long tint;

const int MAX_TEXT = 2000000;

char tagList[256][256];
int n;

struct Tree
{
    Tree(const char *newTag) : tag(newTag) {}
    const char *tag;
    list<Tree> hijos;
    int contar(int k)
    {
        int equ = (strcmp(tagList[k],tag) == 0);
        int res;
        if (k == n-1)
        {
            res = equ;
            forall(it,hijos)
                res += it->contar(k);
        }
        else
        {
            res = 0;
            forall(it,hijos)
                res += it->contar(k+equ);
        }
        return res;
    }
} root("ROOT");

char text[MAX_TEXT];
char* textP = text;

void parse(Tree &r)
{
    while (*textP && textP[1] != '/')
    {
        textP++;
        char *p = textP;
        while (*p != '>' && *p != '/') p++;
        if (*p == '/')
        {
            r.hijos.push_back(Tree(textP));
            *p = 0;
            textP = p+2;
        }
        else
        {
            r.hijos.push_back(Tree(textP));
            *p = 0;
            int k = p - textP;
            textP = p+1;
            parse(r.hijos.back());
            textP += 3 + k;
        }
    }
}

int main()
{
    gets(text);
    parse(root);
    int m;
    scanf("%d",&m);
    string auxLinea;
    getline(cin,auxLinea);
    forn(i,m)
    {
        getline(cin,auxLinea);
        istringstream inpu(auxLinea);
        n = 0;
        while (inpu >> tagList[n]) n++;
        printf("%d\n",root.contar(0));
    }
    return 0;
}