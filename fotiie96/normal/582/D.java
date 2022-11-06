import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int p = sc.nextInt(), a = sc.nextInt();
		BigInteger A = sc.nextBigInteger();
		// BigInteger A = BigInteger.valueOf(10).pow(1000);

		int[] arr = new int[50000];
		int cnt = 0;
		while (!A.equals(BigInteger.ZERO)) {
			arr[cnt++] = A.mod(BigInteger.valueOf(p)).intValue();
			A = A.divide(BigInteger.valueOf(p));
		}

		cnt += 2;

		int[] digits = Arrays.copyOf(arr, cnt);
		for (int l = 0, r = cnt - 1; l < r; ++l, --r) {
			int t = digits[l];
			digits[l] = digits[r];
			digits[r] = t;
		}

		int[][][] am = new int[2][2][cnt];
		int[][][] nam = new int[2][2][cnt];

		fill(am, 0);
		fill(nam, 0);

		am[0][1][0] = 1;

		for (int i = 0; i < cnt; i++) {
			fill(nam, 0);

			int digit = digits[i];
			// System.out.println(digit);

			long[][][][] save = new long[2][2][2][2];
			for (int needCarry = 0; needCarry < 2; needCarry++) {
				for (int same = 0; same < 2; same++) {
					for (int carry = 0; carry < 2; carry++) {
						// do we need carry here?
						for (int nxtSame = 0; nxtSame < 2; nxtSame++) {
							if (same == 0 && nxtSame == 1)
								continue;

							int low, high;
							if (same == 0) {
								// no bound
								if (needCarry == 1) {
									low = p - carry;
									high = p * 2 - 2;
								} else {
									low = 0;
									high = p - 1 - carry;
								}
							} else {
								if (nxtSame == 1) {
									if (needCarry == 1) {
										low = p + digit - carry;
										high = p + digit - carry;
									} else {
										low = digit - carry;
										high = digit - carry;
									}
								} else {
									if (needCarry == 1) {
										low = p - carry;
										high = p + digit - 1 - carry;
									} else {
										low = 0 - carry;
										high = digit - 1 - carry;
									}
								}
							}

							low = Math.max(0, low);
							high = Math.min(2 * p - 2, high);
							if (low <= high) {
								save[needCarry][same][carry][nxtSame] = calculate(
										low, high, p);
							}
						}
					}
				}
			}

			for (int needCarry = 0; needCarry < 2; needCarry++) {
				for (int same = 0; same < 2; same++) {
					for (int prevCarry = 0; prevCarry < cnt; prevCarry++) {
						int c = am[needCarry][same][prevCarry];
						if (c == 0)
							continue;

						for (int carry = 0; carry < 2; carry++) {
							// do we need carry here?
							for (int nxtSame = 0; nxtSame < 2; nxtSame++) {
								if (same == 0 && nxtSame == 1)
									continue;

								long u = nam[carry][nxtSame][prevCarry
										+ needCarry];
								u = (u + save[needCarry][same][carry][nxtSame]
										* c)
										% MOD;
								nam[carry][nxtSame][prevCarry + needCarry] = (int) u;
							}
						}
					}
				}
			}

			int[][][] tmp = am;
			am = nam;
			nam = tmp;
		}

		int ans = 0;
		for (int i = 0; i < cnt; i++) {
			if (i >= a) {
				ans = (ans + am[0][0][i]) % MOD;
				ans = (ans + am[0][1][i]) % MOD;
			}
		}

		System.out.println(ans);
	}

	static final int MOD = (int) (1e9 + 7);

	static long sum(long l, long r) {
		return (l + r) * (r - l + 1) / 2;
	}

	static long calculate(long r, long p) {
		// 0..p-1
		if (r <= p - 1)
			return sum(0, r) + (r + 1);
		return sum(0, p - 1) + p - sum(p, r) + (r - p + 1) * (2 * p - 1);
	}

	static int calculate(int l, int r, int p) {
		long ret = calculate(r, p) - calculate(l - 1, p);
		return (int) (ret % MOD);
	}

	static void fill(int[][][] am, int v) {
		for (int[][] i : am) {
			for (int[] j : i)
				Arrays.fill(j, v);
		}
	}
}