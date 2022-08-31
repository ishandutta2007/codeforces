import java.util.NavigableSet;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.SortedSet;
import java.util.HashMap;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.Random;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		/*for (int i = 1; i <= 3; i++) {
			Counter<Pair<String, String>> popular = new Counter<Pair<String, String>>();
			String lastWord = null;
			for (int j = 1; j <= 50; j++) {
				String fileName = "d:/home/projects/algo/" + i + "/0";
				if (j < 10)
					fileName += "0";
				fileName += j + ".txt";
				try {
					in = new InputReader(new FileInputStream(fileName));
				} catch (FileNotFoundException e) {
					throw new RuntimeException(e);
				}
				Set<Pair<String, String>> current = new HashSet<Pair<String, String>>();
				while (!in.isExhausted()) {
					String word = in.readString();
					while (word.length() > 0 && !Character.isLetter(word.charAt(0)))
						word = word.substring(1);
					while (word.length() > 0 && !Character.isLetter(word.charAt(word.length() - 1)))
						word = word.substring(0, word.length() - 1);
					if (word.length() <= 4)
						continue;
					word = word.toLowerCase();
					if (lastWord != null)
						current.add(Pair.makePair(lastWord, word));
					lastWord = word;
				}
				for (Pair<String, String> word : current)
					popular.add(word);
			}
			Map.Entry<Pair<String, String>, Long>[] array = (Map.Entry<Pair<String, String>, Long>[]) popular.entrySet().toArray(new Map.Entry[popular.size()]);
			Arrays.sort(array, new Comparator<Map.Entry<Pair<String, String>, Long>>() {
				public int compare(Map.Entry<Pair<String, String>, Long> o1, Map.Entry<Pair<String, String>, Long> o2) {
					return Long.signum(o2.getValue() - o1.getValue());
				}
			});
			StringBuilder key = new StringBuilder("keys[" + i + "] = new Pair[]{");
			StringBuilder value = new StringBuilder("values[" + i + "] = new int[]{");
			int cnt = 0;
			for (Map.Entry<Pair<String, String>, Long> anArray : array) {
				cnt++;
				if (anArray.getValue() < 3)
					break;
				key.append("Pair.makePair(\"" + anArray.getKey().first + "\", \"" + anArray.getKey().second + "\"), ");
				value.append(anArray.getValue() + ", ");
			}
			key.append("};");
			value.append("};");
			out.printLine(key);
			out.printLine(value);
		}*/
		Pair<String, String>[][] keys = new Pair[4][];
		int[][] values = new int[4][];
keys[1] = new Pair[]{Pair.makePair("money", "market"), Pair.makePair("foreign", "exchange"), Pair.makePair("london", "march"), Pair.makePair("march", "england"), Pair.makePair("washington", "march"), Pair.makePair("exchange", "rates"), Pair.makePair("market", "today"), Pair.makePair("treasury", "secretary"), Pair.makePair("secretary", "james"), Pair.makePair("treasury", "bills"), Pair.makePair("james", "baker"), Pair.makePair("united", "states"), Pair.makePair("market", "given"), Pair.makePair("march", "treasury"), Pair.makePair("federal", "reserve"), Pair.makePair("house", "appropriations"), Pair.makePair("england", "provided"), Pair.makePair("their", "currencies"), Pair.makePair("around", "billion"), Pair.makePair("appropriations", "committee"), Pair.makePair("treasury's", "baker"), Pair.makePair("tokyo", "march"), Pair.makePair("billion", "billion"), Pair.makePair("record", "billion"), Pair.makePair("market", "assistance"), Pair.makePair("shortage", "around"), Pair.makePair("early", "round"), Pair.makePair("money", "supply"), Pair.makePair("assistance", "london"), Pair.makePair("funds", "trading"), Pair.makePair("system", "today"), Pair.makePair("london", "april"), Pair.makePair("billion", "before"), Pair.makePair("provided", "money"), Pair.makePair("before", "taking"), Pair.makePair("taking", "account"), Pair.makePair("monetary", "policy"), Pair.makePair("early", "assistance"), Pair.makePair("april", "england"), Pair.makePair("central", "banks"), Pair.makePair("revised", "estimate"), Pair.makePair("traded", "daily"), Pair.makePair("bankers", "balances"), Pair.makePair("bills", "maturing"), Pair.makePair("central", "would"), Pair.makePair("drain", "while"), Pair.makePair("discount", "houses"), Pair.makePair("partly", "offsetting"), Pair.makePair("french", "franc"), Pair.makePair("exchequer", "transactions"), Pair.makePair("earlier", "revised"), Pair.makePair("shortage", "system"), Pair.makePair("today", "among"), Pair.makePair("round", "offers"), Pair.makePair("central", "purchased"), Pair.makePair("official", "hands"), Pair.makePair("finance", "ministry"), Pair.makePair("england", "revised"), Pair.makePair("would", "continue"), Pair.makePair("securities", "houses"), Pair.makePair("maturing", "official"), Pair.makePair("their", "dollar"), Pair.makePair("dollar", "sales"), Pair.makePair("currencies", "including"), Pair.makePair("among", "factors"), Pair.makePair("foreign", "exchanges"), Pair.makePair("billion", "march"), Pair.makePair("affecting", "liquidity"), Pair.makePair("billion", "money"), Pair.makePair("purchased", "bills"), Pair.makePair("factors", "affecting"), Pair.makePair("central", "intervention"), Pair.makePair("assistance", "today"), Pair.makePair("dhabi", "march"), Pair.makePair("bought", "about"), Pair.makePair("compares", "bank's"), Pair.makePair("forecast", "shortage"), Pair.makePair("offsetting", "these"), Pair.makePair("offers", "discount"), Pair.makePair("bills", "customer"), Pair.makePair("market", "sources"), Pair.makePair("liquidity", "bills"), Pair.makePair("today", "money"), };
values[1] = new int[]{18, 11, 11, 10, 8, 8, 7, 7, 7, 7, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, };
keys[2] = new Pair[]{Pair.makePair("money", "supply"), Pair.makePair("billion", "billion"), Pair.makePair("federal", "reserve"), Pair.makePair("supply", "rises"), Pair.makePair("supply", "billion"), Pair.makePair("billion", "january"), Pair.makePair("seasonally", "adjusted"), Pair.makePair("billion", "ended"), Pair.makePair("compared", "billion"), Pair.makePair("billion", "december"), Pair.makePair("billion", "february"), Pair.makePair("ended", "march"), Pair.makePair("billion", "previous"), Pair.makePair("billion", "march"), Pair.makePair("deposits", "billion"), Pair.makePair("march", "federal"), Pair.makePair("december", "billion"), Pair.makePair("march", "treasury"), Pair.makePair("washington", "march"), Pair.makePair("adjusted", "billion"), Pair.makePair("loans", "books"), Pair.makePair("revised", "billion"), Pair.makePair("treasury", "latest"), Pair.makePair("business", "loans"), Pair.makePair("private", "sector"), Pair.makePair("billion", "november"), Pair.makePair("billion", "respective"), Pair.makePair("business", "treasury"), Pair.makePair("books", "major"), Pair.makePair("balance", "totaled"), Pair.makePair("respective", "treasury's"), Pair.makePair("balances", "accounts"), Pair.makePair("including", "acceptances"), Pair.makePair("average", "billion"), Pair.makePair("balances", "federal"), Pair.makePair("moving", "average"), Pair.makePair("banks", "billion"), Pair.makePair("previous", "business"), Pair.makePair("treasury", "balances"), Pair.makePair("acceptances", "billion"), Pair.makePair("ended", "february"), Pair.makePair("major", "banks"), Pair.makePair("budget", "statement"), Pair.makePair("operating", "balance"), Pair.makePair("accounts", "billion"), Pair.makePair("billion", "while"), Pair.makePair("totaled", "billion"), Pair.makePair("latest", "budget"), Pair.makePair("billion", "economists"), Pair.makePair("treasury's", "operating"), Pair.makePair("banks", "excluding"), Pair.makePair("statement", "balances"), Pair.makePair("excluding", "acceptances"), Pair.makePair("fixed", "deposits"), Pair.makePair("polled", "reuters"), Pair.makePair("february", "federal"), Pair.makePair("non-personal", "deposits"), Pair.makePair("notice", "personal"), Pair.makePair("money", "market"), Pair.makePair("non-personal", "fixed"), Pair.makePair("week's", "level"), Pair.makePair("supply", "falls"), Pair.makePair("other", "notice"), Pair.makePair("interest", "rates"), Pair.makePair("level", "revised"), Pair.makePair("supply", "growth"), Pair.makePair("totalled", "billion"), Pair.makePair("march", "money"), Pair.makePair("after", "december"), Pair.makePair("while", "four-week"), Pair.makePair("notes", "coins"), Pair.makePair("january", "compared"), Pair.makePair("billion", "money"), Pair.makePair("broadly", "defined"), Pair.makePair("march", "billion"), Pair.makePair("reserve", "previous"), Pair.makePair("economists", "polled"), Pair.makePair("m-1-a", "other"), Pair.makePair("november", "billion"), Pair.makePair("deposits", "residents"), Pair.makePair("residents", "booked"), Pair.makePair("four-week", "moving"), Pair.makePair("which", "m-1-a"), Pair.makePair("foreign", "currency"), Pair.makePair("chequable", "non-personal"), Pair.makePair("interest", "chequable"), Pair.makePair("january", "billion"), Pair.makePair("deposits", "foreign"), Pair.makePair("daily", "interest"), Pair.makePair("january", "after"), Pair.makePair("booked", "chartered"), Pair.makePair("banks", "canada"), Pair.makePair("canada", "m-1-a"), Pair.makePair("billion", "which"), Pair.makePair("m-1-a", "which"), Pair.makePair("which", "daily"), Pair.makePair("previous", "week's"), Pair.makePair("canada", "billion"), Pair.makePair("which", "non-personal"), Pair.makePair("canadian", "money"), Pair.makePair("coins", "circulation"), Pair.makePair("currency", "deposits"), Pair.makePair("previous", "month"), Pair.makePair("chartered", "banks"), Pair.makePair("december", "after"), Pair.makePair("personal", "fixed-term"), Pair.makePair("december", "against"), Pair.makePair("defined", "money"), Pair.makePair("canada", "savings"), Pair.makePair("bonds", "billion"), Pair.makePair("january", "money"), Pair.makePair("banking", "system"), Pair.makePair("billion", "canada"), Pair.makePair("average", "forecast"), Pair.makePair("ottawa", "march"), Pair.makePair("increase", "december"), Pair.makePair("certificates", "deposit"), Pair.makePair("circulation", "totalled"), Pair.makePair("sight", "deposits"), Pair.makePair("circulation", "billion"), Pair.makePair("canadian", "narrowly-defined"), Pair.makePair("securities", "outstanding"), Pair.makePair("singapore", "march"), Pair.makePair("government", "balances"), Pair.makePair("measure", "money"), Pair.makePair("billion", "before"), Pair.makePair("forecast", "called"), Pair.makePair("chartered", "general"), Pair.makePair("general", "loans"), Pair.makePair("short", "assets"), Pair.makePair("deposit", "billion"), Pair.makePair("canadian", "dollar"), Pair.makePair("measures", "notes"), Pair.makePair("march", "business"), Pair.makePair("board", "business"), Pair.makePair("savings", "bonds"), Pair.makePair("billion", "month"), Pair.makePair("assets", "minus"), Pair.makePair("february", "billion"), Pair.makePair("narrowly-defined", "money"), Pair.makePair("foreign", "exchange"), Pair.makePair("dollar", "major"), Pair.makePair("assets", "billion"), Pair.makePair("billion", "total"), Pair.makePair("billion", "seasonally"), Pair.makePair("notes", "circulation"), Pair.makePair("billion", "against"), Pair.makePair("currency", "assets"), Pair.makePair("outstanding", "billion"), Pair.makePair("fixed-term", "deposit"), Pair.makePair("government", "securities"), Pair.makePair("money", "growth"), Pair.makePair("billion", "chartered"), Pair.makePair("bills", "billion"), Pair.makePair("reserve", "board"), Pair.makePair("major", "assets"), Pair.makePair("canadian", "liquid"), Pair.makePair("total", "canadian"), Pair.makePair("liquid", "short"), Pair.makePair("loans", "outstanding"), Pair.makePair("before", "government"), Pair.makePair("march", "canadian"), Pair.makePair("reserve", "march"), Pair.makePair("dropped", "billion"), Pair.makePair("balances", "march"), Pair.makePair("monetary", "policy"), Pair.makePair("authority", "singapore"), Pair.makePair("discount", "window"), Pair.makePair("assets", "chartered"), Pair.makePair("after", "rising"), Pair.makePair("monetary", "authority"), Pair.makePair("billion", "canadian"), Pair.makePair("federal", "funds"), Pair.makePair("december", "compared"), Pair.makePair("after", "increase"), Pair.makePair("march", "canada"), Pair.makePair("treasury", "bills"), Pair.makePair("three", "billion"), Pair.makePair("chartered", "foreign"), Pair.makePair("loans", "washington"), Pair.makePair("billion", "average"), Pair.makePair("billion", "singapore"), Pair.makePair("supply", "seasonally"), Pair.makePair("march", "washington"), Pair.makePair("billion", "compared"), Pair.makePair("balances", "billion"), Pair.makePair("march", "compared"), Pair.makePair("loans", "including"), };
values[2] = new int[]{30, 17, 17, 12, 12, 11, 11, 10, 10, 8, 8, 8, 8, 7, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, };
keys[3] = new Pair[]{Pair.makePair("united", "states"), Pair.makePair("washington", "march"), Pair.makePair("president", "reagan"), Pair.makePair("prime", "minister"), Pair.makePair("tokyo", "march"), Pair.makePair("electronic", "goods"), Pair.makePair("against", "japan"), Pair.makePair("japanese", "electronic"), Pair.makePair("minister", "yasuhiro"), Pair.makePair("white", "house"), Pair.makePair("yasuhiro", "nakasone"), Pair.makePair("trade", "deficit"), Pair.makePair("trade", "surplus"), Pair.makePair("tariffs", "japanese"), Pair.makePair("announced", "plans"), Pair.makePair("trade", "sanctions"), Pair.makePair("japanese", "semiconductor"), Pair.makePair("alleged", "failure"), Pair.makePair("international", "trade"), Pair.makePair("action", "against"), Pair.makePair("plans", "tariffs"), Pair.makePair("world", "markets"), Pair.makePair("economic", "policy"), Pair.makePair("semiconductor", "trade"), Pair.makePair("washington", "announced"), Pair.makePair("trade", "issues"), Pair.makePair("trade", "industry"), Pair.makePair("government", "officials"), Pair.makePair("policy", "council"), Pair.makePair("states", "japan"), Pair.makePair("sanctions", "against"), Pair.makePair("impose", "tariffs"), Pair.makePair("high-level", "official"), Pair.makePair("trade", "washington"), Pair.makePair("billion", "trade"), Pair.makePair("exports", "united"), Pair.makePair("ministry", "international"), Pair.makePair("reuters", "tokyo"), Pair.makePair("japan", "would"), Pair.makePair("march", "prime"), Pair.makePair("ministry", "officials"), Pair.makePair("u.s.-japan", "trade"), Pair.makePair("european", "community"), Pair.makePair("trade", "dispute"), Pair.makePair("trade", "legislation"), Pair.makePair("cut-price", "chips"), Pair.makePair("japanese", "imports"), Pair.makePair("japanese", "companies"), Pair.makePair("retaliation", "japan's"), Pair.makePair("imports", "japanese"), Pair.makePair("washington", "april"), Pair.makePair("committee", "hearing"), Pair.makePair("japanese", "trade"), Pair.makePair("bilateral", "trade"), Pair.makePair("goods", "april"), Pair.makePair("japan", "could"), Pair.makePair("friday", "washington"), Pair.makePair("japan's", "trade"), Pair.makePair("computer", "microchips"), Pair.makePair("tariffs", "trade"), Pair.makePair("billion", "billion"), Pair.makePair("london", "march"), Pair.makePair("called", "japan"), Pair.makePair("microchip", "trade"), Pair.makePair("visit", "washington"), Pair.makePair("japanese", "market"), Pair.makePair("trade", "between"), Pair.makePair("record", "billion"), Pair.makePair("domestic", "market"), Pair.makePair("selling", "cut-price"), Pair.makePair("chips", "world"), Pair.makePair("nakasone", "tokyo"), Pair.makePair("ronald", "reagan"), Pair.makePair("through", "consultations"), Pair.makePair("agreement", "tariffs"), Pair.makePair("against", "japanese"), Pair.makePair("official", "washington"), Pair.makePair("house", "economic"), Pair.makePair("markets", "american-made"), Pair.makePair("heated", "negotiations"), Pair.makePair("semiconductor", "makers"), Pair.makePair("japan", "selling"), Pair.makePair("retaliate", "against"), Pair.makePair("general", "agreement"), Pair.makePair("trade", "representative"), Pair.makePair("third", "countries"), Pair.makePair("agreement", "semiconductor"), Pair.makePair("computer", "chips"), Pair.makePair("semiconductor", "agreement"), Pair.makePair("japanese", "government"), Pair.makePair("trade", "would"), Pair.makePair("tokyo's", "alleged"), Pair.makePair("japan's", "largest"), Pair.makePair("soviet", "union"), Pair.makePair("would", "probably"), Pair.makePair("tokyo's", "failure"), Pair.makePair("official", "reuters"), Pair.makePair("signed", "agreement"), Pair.makePair("foreign", "trade"), Pair.makePair("negotiations", "called"), Pair.makePair("clayton", "yeutter"), Pair.makePair("retaliatory", "action"), Pair.makePair("foreign", "competition"), Pair.makePair("retaliation", "tokyo's"), Pair.makePair("trade", "practices"), Pair.makePair("propose", "joint"), Pair.makePair("representative", "clayton"), Pair.makePair("president", "ronald"), Pair.makePair("goods", "retaliation"), Pair.makePair("electronics", "products"), Pair.makePair("march", "united"), Pair.makePair("march", "japanese"), Pair.makePair("agriculture", "committee"), Pair.makePair("industry", "sources"), Pair.makePair("margaret", "thatcher"), Pair.makePair("senior", "official"), Pair.makePair("house", "agriculture"), Pair.makePair("decision", "impose"), Pair.makePair("states", "officials"), Pair.makePair("trade", "computer"), Pair.makePair("international", "telecommunications"), Pair.makePair("nakasone", "visit"), Pair.makePair("trade", "signed"), Pair.makePair("willy", "clercq"), Pair.makePair("visit", "tokyo"), Pair.makePair("trade", "agreement"), Pair.makePair("boost", "imports"), Pair.makePair("worth", "japanese"), Pair.makePair("foreign", "minister"), Pair.makePair("japan", "violating"), Pair.makePair("think", "there"), Pair.makePair("malcolm", "baldrige"), Pair.makePair("japan", "expected"), Pair.makePair("week-long", "visit"), Pair.makePair("american-made", "semiconductors"), Pair.makePair("about", "foreign"), Pair.makePair("trade", "analysts"), Pair.makePair("japan's", "alleged"), Pair.makePair("world", "trade"), Pair.makePair("higher", "tariffs"), Pair.makePair("miller", "reuters"), Pair.makePair("foreign", "ministry"), Pair.makePair("which", "would"), Pair.makePair("financial", "markets"), Pair.makePair("tariffs", "worth"), Pair.makePair("three", "years"), Pair.makePair("semiconductor", "electronics"), Pair.makePair("could", "react"), Pair.makePair("japanese", "exports"), Pair.makePair("other", "areas"), Pair.makePair("industries", "association"), Pair.makePair("trade", "miller"), Pair.makePair("democratic", "leader"), Pair.makePair("japan", "trade"), Pair.makePair("secretary", "malcolm"), Pair.makePair("there", "immediate"), Pair.makePair("commerce", "secretary"), Pair.makePair("senate", "democratic"), Pair.makePair("leader", "robert"), Pair.makePair("trade", "action"), Pair.makePair("countries", "their"), Pair.makePair("reagan", "might"), Pair.makePair("protectionist", "trade"), Pair.makePair("reuters", "london"), Pair.makePair("tariffs", "april"), Pair.makePair("their", "trade"), Pair.makePair("cable", "wireless"), Pair.makePair("kyodo", "service"), Pair.makePair("trade", "friction"), Pair.makePair("alleged", "unfair"), Pair.makePair("minister", "margaret"), Pair.makePair("association", "japan"), Pair.makePair("financial", "services"), Pair.makePair("semiconductor", "manufacturers"), Pair.makePair("trade", "imbalances"), Pair.makePair("markets", "goods"), Pair.makePair("settle", "dispute"), Pair.makePair("action", "would"), Pair.makePair("tariffs", "would"), Pair.makePair("concerned", "about"), Pair.makePair("ruling", "liberal"), Pair.makePair("third", "world"), Pair.makePair("peking", "march"), Pair.makePair("japan", "because"), Pair.makePair("goods", "services"), Pair.makePair("semiconductor", "industry"), Pair.makePair("democratic", "party"), Pair.makePair("increase", "imports"), Pair.makePair("tariffs", "effect"), Pair.makePair("washington", "white"), Pair.makePair("failure", "microchip"), Pair.makePair("electronic", "industries"), Pair.makePair("settle", "their"), Pair.makePair("liberal", "democratic"), Pair.makePair("japanese", "makers"), Pair.makePair("trade", "sources"), Pair.makePair("agreement", "reached"), Pair.makePair("signed", "september"), Pair.makePair("reagan", "would"), Pair.makePair("while", "japan"), Pair.makePair("government", "sources"), Pair.makePair("trade", "problems"), Pair.makePair("duties", "japanese"), };
values[3] = new int[]{29, 21, 16, 15, 14, 12, 12, 11, 10, 10, 10, 10, 10, 10, 9, 9, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, };
		Map<Pair<String, String>, Integer>[] maps = new Map[4];
		int[] score = new int[4];
		for (int i = 1; i <= 3; i++) {
			maps[i] = new CPPMap<Pair<String, String>, Integer>(new Factory<Integer>() {
				public Integer create() {
					return 0;
				}
			});
			for (int j = 0; j < keys[i].length; j++)
				maps[i].put(keys[i][j], values[i][j]);
		}
		String lastWord = null;
		while (!in.isExhausted()) {
			String word = in.readString();
			while (word.length() > 0 && !Character.isLetter(word.charAt(0)))
				word = word.substring(1);
			while (word.length() > 0 && !Character.isLetter(word.charAt(word.length() - 1)))
				word = word.substring(0, word.length() - 1);
			if (word.length() <= 4)
				continue;
			word = word.toLowerCase();
			if (lastWord != null) {
				for (int i = 1; i <= 3; i++)
					score[i] += maps[i].get(Pair.makePair(lastWord, word));
			}
			lastWord = word;
		}
		int answer = ListUtils.maxIndex(Array.wrap(score));
		out.printLine(answer);
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public boolean isExhausted() {
		int value;
		while (isSpaceChar(value = peek()) && value != -1)
			read();
		return value == -1;
	}

	}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}

	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}

class CPPMap<K, V> extends HashMap<K, V> {
	private final Factory<V> defaultValueFactory;

	public CPPMap(Factory<V> defaultValueFactory) {
		this.defaultValueFactory = defaultValueFactory;
	}

	public V get(Object key) {
		if (containsKey(key))
			return super.get(key);
		V value = defaultValueFactory.create();
		try {
			//noinspection unchecked
			super.put((K) key, value);
			return value;
		} catch (ClassCastException e) {
			return value;
		}
	}
}

interface Factory<V> {
	public V create();
}

class ListUtils {
	public static<T> int find(List<T> sequence, T value) {
		int size = sequence.size();
		for (int i = 0; i < size; i++) {
			if (MiscUtils.equals(sequence.get(i), value))
				return i;
		}
		return size;
	}

	public static<T extends Comparable<T>> int maxIndex(List<T> sequence) {
		return find(sequence, CollectionUtils.maxElement(sequence));
	}

	}

abstract class Array<T> extends AbstractList<T> implements RandomAccess {

	public static List<Integer> wrap(int...array) {
		return new IntArray(array);
	}

	protected static class IntArray extends Array<Integer> {
		protected final int[] array;

		protected IntArray(int[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Integer get(int index) {
			return array[index];
		}

		public Integer set(int index, Integer value) {
			int result = array[index];
			array[index] = value;
			return result;
		}
	}

	}

class MiscUtils {

	public static<T> boolean equals(T first, T second) {
		return first == null && second == null || first != null && first.equals(second);
	}

	}

class CollectionUtils {

	public static<T extends Comparable<T>> T maxElement(Iterable<T> collection) {
		T result = null;
		for (T element : collection) {
			if (result == null || result.compareTo(element) < 0)
				result = element;
		}
		return result;
	}

	}