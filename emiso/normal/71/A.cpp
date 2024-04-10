#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string nome;  
    int n,i;  
    scanf("%d ",&n);
    for(i=0;i<n;i++)
    {
                    cin >> nome;
                    if(nome.length()<=10) cout << nome << endl;
                    else printf("%c%d%c\n",nome[0],nome.length()-2,nome[nome.length()-1]);
    }
    return 0;
}