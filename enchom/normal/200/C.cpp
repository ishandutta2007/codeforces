#include <iostream>
#include <algorithm>
using namespace std;
struct footballteam
{
    char name[25];
    int nameL,goals,misses,points,gamesplayed;
};
footballteam teams[5],faketeams[5];
int knownteams=0;

bool Same(char team1[],int L1,char team2[],int L2)
{
    if (L1!=L2)
    return false;
    else
    {
        int i;
        for (i=1;i<=L1;i++)
        {
            if (team1[i]!=team2[i])
            return false;
        }
        return true;
    }
}

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

bool IsFirstSmaller(footballteam a,footballteam b)
{
    int i;
    for (i=1;i<=MIN(a.nameL,b.nameL);i++)
    {
        if (a.name[i]<b.name[i])
        return true;
        else if (a.name[i]>b.name[i])
        return false;
    }
    if (b.nameL>a.nameL)
    return true;
    else
    return false;
}

bool SortEm(footballteam a,footballteam b)
{
    if (a.points<b.points)
    return true;
    else if (a.points>b.points)
    return false;
    else
    {
        if (a.goals-a.misses<b.goals-b.misses)
        return true;
        else if (a.goals-a.misses>b.goals-b.misses)
        return false;
        else
        {
            if (a.goals<b.goals)
            return true;
            else if (a.goals>b.goals)
            return false;
            else
            {
                return !IsFirstSmaller(a,b);
            }
        }
    }
}

int main()
{
    string team1,team2,goals;
    char team1C[25],team2C[25];
    int bestgoals1=-1,bestgoals2=-1;
    char playagainst[25]={'0','B','E','R','L','A','N','D'},paL=7;
    char berland[25]={'0','B','E','R','L','A','N','D'},bL=7;
    int t1L,t2L;
    bool alredyknowteam;
    int team1goals,team2goals;
    int i,j,in,ja;
    for (i=1;i<=5;i++)
    {
        cin>>team1>>team2>>goals;
        team1goals=(int)( goals[0]-'0' );
        team2goals=(int)( goals[2]-'0' );
        for (j=0;j<team1.length();j++)
        {
            team1C[j+1]=team1[j];
        }
        t1L=team1.length();
        
        for (j=0;j<team2.length();j++)
        {
            team2C[j+1]=team2[j];
        }
        t2L=team2.length();
        
        alredyknowteam=false;
        for (j=1;j<=knownteams;j++)
        {
            if (Same(teams[j].name,teams[j].nameL,team1C,t1L))
            {
                alredyknowteam=true;
                teams[j].goals+=team1goals;
                
                if (team1goals>team2goals)
                teams[j].points+=3;
                else if (team1goals==team2goals)
                teams[j].points++;
                
                teams[j].misses+=team2goals;;

                teams[j].gamesplayed++;
                break;
            }
        }
        if (!alredyknowteam)
        {
            knownteams++;
            teams[knownteams].misses=team2goals;
            teams[knownteams].goals=team1goals;
            teams[knownteams].gamesplayed=1;
            if (team1goals>team2goals)
            teams[knownteams].points=3;
            else if (team1goals==team2goals)
            teams[knownteams].points=1;
            else
            teams[knownteams].points=0;
            
            teams[knownteams].nameL=t1L;
            for (j=1;j<=t1L;j++)
            teams[knownteams].name[j]=team1C[j];
        }
        ///Team 2
        alredyknowteam=false;
        for (j=1;j<=knownteams;j++)
        {
            if (Same(teams[j].name,teams[j].nameL,team2C,t2L))
            {
                alredyknowteam=true;
                teams[j].goals+=team2goals;
                
                if (team2goals>team1goals)
                teams[j].points+=3;
                else if (team2goals==team1goals)
                teams[j].points++;
                
                teams[j].misses+=team1goals;
                teams[j].gamesplayed++;
            }
        }
        if (!alredyknowteam)
        {
            knownteams++;
            teams[knownteams].misses=team1goals;
            teams[knownteams].goals=team2goals;
            teams[knownteams].gamesplayed=1;
            if (team2goals>team1goals)
            teams[knownteams].points=3;
            else if (team2goals==team1goals)
            teams[knownteams].points=1;
            else
            teams[knownteams].points=0;
            
            teams[knownteams].nameL=t2L;
            for (j=1;j<=t2L;j++)
            teams[knownteams].name[j]=team2C[j];
        }
    }
    sort(teams+1,teams+1+knownteams,SortEm);
    for (i=1;i<=knownteams;i++)
    {
        if (teams[i].gamesplayed==2)
        {
            if (!Same(teams[i].name,teams[i].nameL,playagainst,paL))
            {
                for (j=1;j<=teams[i].nameL;j++)
                {
                    playagainst[j]=teams[i].name[j];
                }
                paL=teams[i].nameL;
                break;
            }
        }
    }
    for (i=1;i<=300;i++)
    {
        for (j=0;j<=i-1;j++)
        {
            for (in=1;in<=knownteams;in++)
            faketeams[in]=teams[in];
            
            for (in=1;in<=knownteams;in++)
            {
                if (Same(teams[in].name,teams[in].nameL,berland,bL))
                {
                    faketeams[in].goals+=i;
                    faketeams[in].misses+=j;
                    faketeams[in].points+=3;
                }
                else if (Same(teams[in].name,teams[in].nameL,playagainst,paL))
                {
                    faketeams[in].goals+=j;
                    faketeams[in].misses+=i;
                }
            }
            sort(faketeams+1,faketeams+1+knownteams,SortEm);
            if (Same(faketeams[3].name,faketeams[3].nameL,berland,bL) || Same(faketeams[4].name,faketeams[4].nameL,berland,bL))
            {
                if (bestgoals1==-1)
                {
                    bestgoals1=i;
                    bestgoals2=j;
                }
                else if (i-j<bestgoals1-bestgoals2)
                {
                    bestgoals1=i;
                    bestgoals2=j;
                }
                else if (i-j==bestgoals1-bestgoals2)
                {
                    if (j<bestgoals2)
                    {
                        bestgoals1=i;
                        bestgoals2=j;
                    }
                }
            }
        }
    }
    if (bestgoals1!=-1)
    cout<<bestgoals1<<':'<<bestgoals2<<endl;
    else
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}