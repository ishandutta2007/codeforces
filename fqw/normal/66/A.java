import java.lang.*;
import java.util.*;
import java.math.*;

public class Main {
    static public void main(String[] args) {
        BigInteger n = (new Scanner(System.in)).nextBigInteger();
        if (n.compareTo(new BigInteger("-128")) >= 0 && n.compareTo(new BigInteger("127")) <= 0) {
            System.out.println("byte");
        } else if (n.compareTo(new BigInteger("-32768")) >= 0
            && n.compareTo(new BigInteger("32767")) <= 0) {
            System.out.println("short");
        } else if (n.compareTo(new BigInteger("-2147483648")) >= 0
            && n.compareTo(new BigInteger("2147483647")) <= 0) {
            System.out.println("int");
        } else if (n.compareTo(new BigInteger("-9223372036854775808")) >= 0
            && n.compareTo(new BigInteger("9223372036854775807")) <= 0) {
            System.out.println("long");
        } else {
            System.out.println("BigInteger");
        }
    }
}