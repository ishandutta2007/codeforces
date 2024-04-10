#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int Check(string a)
{
    if (a=="C")
    return 1;
    else if (a=="C#")
    return 2;
    else if (a=="D")
    return 3;
    else if (a=="D#")
    return 4;
    else if (a=="E")
    return 5;
    else if (a=="F")
    return 6;
    else if (a=="F#")
    return 7;
    else if (a=="G")
    return 8;
    else if (a=="G#")
    return 9;
    else if (a=="A")
    return 10;
    else if (a=="B")
    return 11;
    else if (a=="H")
    return 12;
}

int main()
{
    string a,b,c;
    string help;
    Int first=0,second=0,third=0;
    Int dist12,dist23;
    
    cin>>a>>b>>c;
    
    first=Check(a);
    second=Check(b);
    third=Check(c);
    
    if (first>second)
    {
        dist12=12-first+second;
    }
    else
    {
        dist12=second-first;
    }
    
    if (second>third)
    {
        dist23=12-second+third;
    }
    else
    {
        dist23=third-second;
    }
    
    if (dist12==4 && dist23==3)
    {
        printf("major\n");
        return 0;
    }
    else if (dist12==3 && dist23==4)
    {
        printf("minor\n");
        return 0;
    }
    
    ///////////////////////////////////////////
    
    first=Check(a);
    second=Check(c);
    third=Check(b);
    
    if (first>second)
    {
        dist12=12-first+second;
    }
    else
    {
        dist12=second-first;
    }
    
    if (second>third)
    {
        dist23=12-second+third;
    }
    else
    {
        dist23=third-second;
    }
    
    if (dist12==4 && dist23==3)
    {
        printf("major\n");
        return 0;
    }
    else if (dist12==3 && dist23==4)
    {
        printf("minor\n");
        return 0;
    }
    /////////////////////////////////////////////
    first=Check(b);
    second=Check(a);
    third=Check(c);
    
    if (first>second)
    {
        dist12=12-first+second;
    }
    else
    {
        dist12=second-first;
    }
    
    if (second>third)
    {
        dist23=12-second+third;
    }
    else
    {
        dist23=third-second;
    }
    
    if (dist12==4 && dist23==3)
    {
        printf("major\n");
        return 0;
    }
    else if (dist12==3 && dist23==4)
    {
        printf("minor\n");
        return 0;
    }
    ///////////////////////////////////////////////
    first=Check(b);
    second=Check(c);
    third=Check(a);
    
    if (first>second)
    {
        dist12=12-first+second;
    }
    else
    {
        dist12=second-first;
    }
    
    if (second>third)
    {
        dist23=12-second+third;
    }
    else
    {
        dist23=third-second;
    }
    
    if (dist12==4 && dist23==3)
    {
        printf("major\n");
        return 0;
    }
    else if (dist12==3 && dist23==4)
    {
        printf("minor\n");
        return 0;
    }
    ///////////////////////////////////////////
    first=Check(c);
    second=Check(a);
    third=Check(b);
    
    if (first>second)
    {
        dist12=12-first+second;
    }
    else
    {
        dist12=second-first;
    }
    
    if (second>third)
    {
        dist23=12-second+third;
    }
    else
    {
        dist23=third-second;
    }
    
    if (dist12==4 && dist23==3)
    {
        printf("major\n");
        return 0;
    }
    else if (dist12==3 && dist23==4)
    {
        printf("minor\n");
        return 0;
    }
    /////////////////////////////////////////////
    first=Check(c);
    second=Check(b);
    third=Check(a);
    
    if (first>second)
    {
        dist12=12-first+second;
    }
    else
    {
        dist12=second-first;
    }
    
    if (second>third)
    {
        dist23=12-second+third;
    }
    else
    {
        dist23=third-second;
    }
    
    if (dist12==4 && dist23==3)
    {
        printf("major\n");
        return 0;
    }
    else if (dist12==3 && dist23==4)
    {
        printf("minor\n");
        return 0;
    }
    
    printf("strange\n");
    return 0;
}