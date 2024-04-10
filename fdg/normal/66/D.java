/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

//package javaapplication1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

    /**
     * @param args the command line arguments
     */

    public static void main(String[] args) {
        try
        {
            BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
            int n=Integer.parseInt(r.readLine());
            if (n==2)
            {
                System.out.println("-1");
                return;
            }
            BigInteger ans[]=new BigInteger[n+1];
            int prime[]=new int[n+1],cur=0;
            for(int t=2;cur<n;t++)
            {
                boolean pr=true;
                for(int i=2;i<t;i++)
                    if (t%i==0)
                    {
                        pr=false;
                        break;
                    }
                if (pr)
                {
                    prime[cur]=t;
                    cur++;
                }
            }
            for(int i=0;i<n;i++)
                ans[i]=BigInteger.ONE;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if (i==j) continue;
                    ans[j]=ans[j].multiply(BigInteger.valueOf(prime[i]));
                }
            }
            for(int i=0;i<n;i++)
                System.out.println(ans[i]);
        }
        catch (Exception e) {System.err.print(e);}
    }

}