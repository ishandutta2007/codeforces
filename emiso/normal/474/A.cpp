//EM NOME DE ABELLA
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    char lado,str[102];
    string a = "qwertyuiopasdfghjkl;zxcvbnm,./" ,str1;
    scanf("%c ",&lado);
    int iae,i,j;
    if (lado=='R') iae=-1;
    else iae=1;
    scanf("%s",str);
    str1=str;
    for(i=0;i<str1.size();i++)
    {
         for(j=0;j<30;j++)
         {
                          if(str1[i]==a[j]) {
                                            str1[i]=a[j+iae];
                                            j=30;
                          }
         }
    }
    cout << str1;
    return 0;
}